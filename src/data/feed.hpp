#ifndef __FEED_HPP__
#define __FEED_HPP__

class Article;

#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QUrl>

class Feed : public QObject {

	Q_OBJECT

	Q_PROPERTY(QString title READ getTitle CONSTANT);
	Q_PROPERTY(bool hasUnreadArticles READ hasUnreadArticles NOTIFY unreadArticlesChanged);
	Q_PROPERTY(unsigned int unreadArticlesCount READ unreadArticlesCount NOTIFY unreadArticlesCountChanged);

public:
	Feed(int id, QString title, QUrl feedUrl, QList<Article*> articles);
	virtual ~Feed();

	int getId() const;
	QString getTitle() const;
	QUrl getUrl() const;
	QList<Article*> getArticles() const;

	bool hasUnreadArticles() const;
	unsigned int unreadArticlesCount() const;
	QList<Article*> unreadArticles() const;

	void addArticle(Article* article);

Q_SIGNALS:
	void unreadArticlesChanged(bool hasUnreadArticles);
	void unreadArticlesCountChanged(unsigned int unreadArticlesCount);

private:
	int				_id;
	QString			_title;
	QUrl			_feedUrl;
	QList<Article*>	_articles;
};

inline int Feed::getId() const {
	return _id;
}

inline QString Feed::getTitle() const {
	return _title;
}

inline QUrl Feed::getUrl() const {
	return _feedUrl;
}

inline QList<Article*> Feed::getArticles() const {
	return _articles;
}

#endif // __FEED_HPP__
