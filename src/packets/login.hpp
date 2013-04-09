#ifndef __LOGIN_HPP__
#define __LOGIN_HPP__

#include "apacket.hpp"

class Login : public APacket {
public:
	Login(QString login, QString password, TTRSSManager* manager, unsigned long long id);
	virtual ~Login();

	virtual void handleSuccess(QMap<QString, QVariant> reply);
	virtual void handleError(QMap<QString, QVariant> reply);

protected:
	virtual QVariantMap getRequestDataImpl() const;

private:
	QString	_login;
	QString	_password;
};

#endif // __LOGIN_HPP__
