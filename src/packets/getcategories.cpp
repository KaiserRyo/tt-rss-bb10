#include "getcategories.hpp"

#include "ttrssmanager.hpp"

#include "data/category.hpp"

#include <QtCore/QDebug>

namespace ttrss {
	namespace packets {
		GetCategories::GetCategories(	bool unreadOnly,
										bool enableNested,
										bool includeEmpty,
										TTRSSManager* manager,
										unsigned long long id) :
											APacket(manager, id),
											_unreadOnly(unreadOnly),
											_enableNested(enableNested),
											_includeEmpty(includeEmpty) {
		}

		GetCategories::~GetCategories() {
		}

		void GetCategories::handleSuccess(QVariant reply) {
			QList<QVariant> lReply = reply.toList();
			for (QList<QVariant>::ConstIterator it = lReply.constBegin(), end = lReply.constEnd(); it != end; ++it) {
				QMap<QString, QVariant> mCategory = it->toMap();
				data::Category* category = new data::Category(mCategory.value("id").toInt(), mCategory.value("title").toString(), QList<data::Feed*>());
				bool newCategory = getManager()->addCategory(category);
				getManager()->requestFeeds(category->getId());
				if (!newCategory)
					delete category;
			}
		}

		void GetCategories::handleError(QVariant /*reply*/) {
			qDebug() << "GetCategories::error";
		}

		QVariantMap GetCategories::getRequestDataImpl() const {
			QVariantMap packet;
			packet["op"] = "getCategories";
			packet["unread_only"] = _unreadOnly;
			packet["enable_nested"] = _enableNested;
			packet["include_empty"] = _includeEmpty;
			return packet;
		}
	}
}
