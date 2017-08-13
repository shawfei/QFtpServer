#ifndef FTPCOMMAND_H
#define FTPCOMMAND_H

#include <QObject>

class QSslSocket;

// The base class for all FTP commands that need a data connection.

class FtpCommand : public QObject
{
    Q_OBJECT
public:
    explicit FtpCommand(QObject *parent = 0);
    ~FtpCommand();

signals:
    void finished(const QString &errorText);

public:
    void start(QSslSocket *socket);

protected:
    virtual void startImplementation() = 0;
    QSslSocket* socket;
    QString errorText;
};

#endif // FTPCOMMAND_H
