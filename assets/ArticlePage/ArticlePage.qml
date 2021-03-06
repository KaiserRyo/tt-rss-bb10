import bb.cascades 1.0

Page {
    property variant article
    
    titleBar: TitleBar {
        title: article.title
        visibility: ChromeVisibility.Visible
    } // titleBar
    
    Container {
        layout: StackLayout {}
        
        ScrollView {
	    	layoutProperties: StackLayoutProperties {
	    		spaceQuota: 1
	    	}
	    	
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            
            scrollViewProperties {
	            scrollMode: ScrollMode.Both
	            pinchToZoomEnabled: true
	            minContentScale: 0.75
	            maxContentScale: 5
	        }
	        
	        onContentScaleChanged: {
	            webView.settings.viewport = {
	                "initial-scale": scale
	            }
	        }
            
            WebView {
	            id: webView
	            html: article.content
	            
	            settings.viewport: {
	                "initial-scale": 1.0
	            }
	            
	            onNavigationRequested: {
	                if (request.url == "local:///") {
	                    request.action = WebNavigationRequestAction.Accept;
	                } else {
	                    request.action = WebNavigationRequestAction.Ignore;
	                    invokeQuery.uri = request.url;
	                    invokeBrowser.trigger("bb.action.OPEN");
	                }
	            }
	        } // Web view
        } // Scroll view
        
        ProgressIndicator {
            layoutProperties: StackLayoutProperties {
                spaceQuota: -1
            }
            visible: webView.loading
            toValue: 100
            value: webView.loadProgress
            horizontalAlignment: HorizontalAlignment.Fill
        }
    }
    
    actions: [
        ActionItem {
            title: article.unread ? qsTr("Mark as read") : qsTr("Keep unread")
            imageSource: article.unread ? "asset:///images/mark_as_read.png" : "asset:///images/keep_unread.png"
            ActionBar.placement: ActionBarPlacement.OnBar

            onTriggered: {
                article.unread = !article.unread
            }
        }, // Keep unread
        ActionItem {
            title: article.published ? qsTr("Unpublish") : qsTr("Publish")
            imageSource: article.published ? "asset:///images/unpublish.png" : "asset:///images/publish.png"
            ActionBar.placement: ActionBarPlacement.OnBar

            onTriggered: {
                article.published = !article.published
            }
        }, // Publish
        ActionItem {
            title: article.marked ? qsTr("Unstar") : qsTr("Star")
            imageSource: article.marked ? "asset:///images/unstar.png" : "asset:///images/star.png"
            ActionBar.placement: ActionBarPlacement.OnBar

            onTriggered: {
                article.marked = !article.marked
            }
        }, // Star
        InvokeActionItem {
            id: share
            query {
                invokeActionId: "bb.action.SHARE"
            }
        }, // Share
        InvokeActionItem {
            title: qsTr("Open in browser")
            imageSource: "asset:///images/ic_open_link.png"
            id: openInBrowser
            
            query {
                invokeActionId: "bb.action.OPEN"
                invokeTargetId: "sys.browser"
            }
        }
    ] // Actions
    
    attachedObjects: [
        Invocation {
            id: invokeBrowser
            query: InvokeQuery {
                id: invokeQuery
                invokeTargetId: "sys.browser"
                onQueryChanged: invokeQuery.updateQuery()
            }
        } // Browser invocation
    ] // Attached objects
    
    onArticleChanged: {
        share.query.uri = article.link.toString();
        share.query.updateQuery();
        openInBrowser.query.uri = article.link.toString();
        openInBrowser.query.updateQuery();
    }
}
