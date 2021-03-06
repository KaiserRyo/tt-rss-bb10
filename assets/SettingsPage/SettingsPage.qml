import bb.cascades 1.0

Page {
    titleBar: TitleBar {
        title: qsTr("Settings")
        visibility: ChromeVisibility.Visible
    } // titleBar
    ScrollView {
        horizontalAlignment: HorizontalAlignment.Fill
        Container {
            Container {
                leftPadding: 20
                rightPadding: 20
                horizontalAlignment: HorizontalAlignment.Fill
                Label {
                    text: qsTr("Server")
                }
                Container {
                    leftPadding: 40
                    Label {
                        text: qsTr("Address")
                    }
                    TextField {
                        id: serverAddress
                        objectName: "serverAddress"
                        inputMode: TextFieldInputMode.Url
                        text: _settings.getValueFor(objectName, "")
                        onTextChanged: {
                            _settings.saveValueFor(serverAddress.objectName, text);
                        }
                    }
                } // Address
                Container {
                    leftPadding: 40
                    Label {
                        text: qsTr("Login")
                    }
                    TextField {
                        id: serverLogin
                        objectName: "serverLogin"
                        text: _settings.getValueFor(objectName, "")
                        onTextChanged: {
                            _settings.saveValueFor(serverLogin.objectName, text);
                        }
                    }
                } // Login
                Container {
                    leftPadding: 40
                    Label {
                        text: qsTr("Password")
                    }
                    TextField {
                        id: serverPassword
                        objectName: "serverPassword"
                        inputMode: TextFieldInputMode.Password
                        text: _settings.getValueFor(objectName, "")
                        onTextChanged: {
                            _settings.saveValueFor(serverPassword.objectName, text);
                        }
                    }
                } // Password
                Container {
                    leftPadding: 40
                    horizontalAlignment: HorizontalAlignment.Fill
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight

                    }
                    Label {
                        text: qsTr("Ignore SSL errors")
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1.0

                        }
                    }
                    ToggleButton {
                        id: ignoreSslErrors
                        objectName: "ignoreSslErrors"
                        checked: _settings.getValueFor(objectName, false)
                        onCheckedChanged: {
                            _settings.saveValueFor(ignoreSslErrors.objectName, checked);
                        }
                    }
                } // Ignore SSL errors
            } // Server settings
            Divider {}
            Container {
                leftPadding: 20
                rightPadding: 20
                horizontalAlignment: HorizontalAlignment.Fill
                Label {
                    text: qsTr("UI")
                }
                Container {
                    leftPadding: 40
                    horizontalAlignment: HorizontalAlignment.Fill
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight

                    }
                    Label {
                        text: qsTr("Display only unread articles")
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1.0

                        }
                    }
                    ToggleButton {
                        id: unreadOnly
                        objectName: "unreadOnly"
                        checked: _settings.getValueFor(objectName, true);
                        onCheckedChanged: {
                            _settings.saveValueFor(unreadOnly.objectName, checked);
                        }
                    }
                } // Unread only
                Container {
                    leftPadding: 40
                    horizontalAlignment: HorizontalAlignment.Fill
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight

                    }
                    Label {
                        text: qsTr("Display oldest articles first")
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1.0

                        }
                    }
                    ToggleButton {
                        id: articlesOldestFirst
                        objectName: "articlesOldestFirst"
                        checked: _settings.getValueFor(objectName, true)
                        onCheckedChanged: {
                            _settings.saveValueFor(articlesOldestFirst.objectName, checked);
                        }
                    }
                } // Unread only
            } // Server settings
            Divider {
            }
        } // Main scrollview container
    } // ScrollView
} // Page
