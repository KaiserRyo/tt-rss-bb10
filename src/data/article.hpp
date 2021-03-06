#ifndef __ARTICLE_HPP__
#define __ARTICLE_HPP__

namespace ttrss {
	class TTRSSManager;
}

#include "data/feed.hpp"

#include <QtCore/QDate>
#include <QtCore/QDateTime>
#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QTime>
#include <QtCore/QUrl>
#include <QtCore/QVariant>

namespace ttrss {
	namespace data {
		class Article : public QObject {

			Q_OBJECT

			Q_PROPERTY(QString title READ getTitle CONSTANT);
			Q_PROPERTY(QString content READ getContent WRITE setContent NOTIFY contentChanged);
			Q_PROPERTY(QString excerpt READ getExcerpt CONSTANT);
			Q_PROPERTY(QString author READ getAuthor CONSTANT);
			Q_PROPERTY(QDateTime updated READ getUpdated CONSTANT);
			Q_PROPERTY(QDate updatedDate READ getUpdatedDate CONSTANT);
			Q_PROPERTY(QTime updatedTime READ getUpdatedTime CONSTANT);
			Q_PROPERTY(QUrl link READ getLink CONSTANT);
			Q_PROPERTY(bool unread READ isUnread WRITE setUnread NOTIFY unreadChanged);
			Q_PROPERTY(bool marked READ isMarked WRITE setMarked NOTIFY markedChanged);
			Q_PROPERTY(bool published READ isPublished WRITE setPublished NOTIFY publishedChanged);
			Q_PROPERTY(QVariant feed READ getFeedVariant CONSTANT);
			Q_PROPERTY(QVariant icon READ getIcon CONSTANT);

		public:
			// TODO: complete attributes
			Article(TTRSSManager* manager = NULL,
					unsigned int id = 0,
					QString title = "",
					QList<QString> labels = QList<QString>(),
					bool unread = false,
					bool marked = false,
					bool published = false,
					unsigned int updated = 0,
					QString excerpt = "",
					QString content = "",
					bool loaded = false,
					QUrl link = QUrl(),
					Feed* feed = NULL);
			Article(const Article& other);
			virtual ~Article();

			unsigned int getId() const;
			QString getTitle() const;
			QList<QString> getLabels() const;
			bool isUnread() const;
			void setUnread(bool unread);
			bool isMarked() const;
			void setMarked(bool marked);
			bool isPublished() const;
			void setPublished(bool published);
			QString getComments() const;
			QString getExcerpt() const;
			QString getContent();
			void setContent(QString content);
			bool isLoaded() const;
			QString getAuthor() const;
			QDateTime getUpdated() const;
			QDate getUpdatedDate() const;
			QTime getUpdatedTime() const;
			QUrl getLink() const;
			Feed* getFeed() const;
			QVariant getFeedVariant() const;
			QVariant getIcon() const;	// TODO: find how to access feed.icon from QML and remove this

			Q_INVOKABLE void load();

		Q_SIGNALS:
			void contentChanged(QString newContent);
			void unreadChanged(bool isUnread);
			void markedChanged(bool isMarked);
			void publishedChanged(bool isPublished);

		private:
			TTRSSManager*	_manager;
			unsigned int	_id;
			QString			_title;
			QList<QString>	_labels;
			bool			_unread;
			bool			_marked;
			bool			_published;
			QString			_comments;
			QString			_author;
			QDateTime		_updated;
			QString			_excerpt;
			QString			_content;
			bool			_loaded;
			QUrl			_link;
			Feed*			_feed;
			// TODO: feed_id
			// TODO: attachments
		};

		inline unsigned int Article::getId() const {
			return _id;
		}

		inline QString Article::getTitle() const {
			return _title;
		}

		inline QUrl Article::getLink() const {
			return _link;
		}

		inline QList<QString> Article::getLabels() const {
			return _labels;
		}

		inline bool Article::isUnread() const {
			return _unread;
		}

		inline bool Article::isMarked() const {
			return _marked;
		}

		inline bool Article::isPublished() const {
			return _published;
		}

		inline QString Article::getComments() const {
			return _comments;
		}

		inline QString Article::getAuthor() const {
			return _author;
		}

		inline QDateTime Article::getUpdated() const {
			return _updated;
		}

		inline QDate Article::getUpdatedDate() const {
			return _updated.date();
		}

		inline QTime Article::getUpdatedTime() const {
			return _updated.time();
		}

		inline QString Article::getExcerpt() const {
			return _excerpt;
		}

		inline bool Article::isLoaded() const {
			return _loaded;
		}

		inline Feed* Article::getFeed() const {
			return _feed;
		}

		inline QVariant Article::getFeedVariant() const {
			return QVariant::fromValue(_feed);
		}

		inline QVariant Article::getIcon() const {
			return _feed->getIcon();
		}
	}
}

Q_DECLARE_METATYPE(ttrss::data::Article);
Q_DECLARE_METATYPE(ttrss::data::Article*);

#endif // __ARTICLE_HPP__
