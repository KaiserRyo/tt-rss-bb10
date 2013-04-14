#ifndef __FEED_HPP__
#define __FEED_HPP__

namespace ttrss {
	namespace data {
		class Article;
	}
}

#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtCore/QVariant>

namespace ttrss {
	namespace data {
		class Feed : public QObject {

			Q_OBJECT

			Q_PROPERTY(int id READ getId CONSTANT);
			Q_PROPERTY(QString title READ getTitle CONSTANT);
			Q_PROPERTY(QUrl url READ getUrl CONSTANT);
			Q_PROPERTY(bool hasUnreadArticles READ hasUnreadArticles NOTIFY unreadArticlesChanged);
			Q_PROPERTY(unsigned int unreadArticlesCount READ unreadArticlesCount NOTIFY unreadArticlesCountChanged);

		public:
			Feed(int id = -1, QString title = "", QUrl feedUrl = QUrl(), QList<Article*> articles = QList<Article*>());
			Feed(const Feed& other);
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
	}
}

Q_DECLARE_METATYPE(ttrss::data::Feed);
Q_DECLARE_METATYPE(ttrss::data::Feed*);

#endif // __FEED_HPP__
