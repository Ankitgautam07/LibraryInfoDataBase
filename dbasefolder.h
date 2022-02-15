#ifndef DBASEFOLDER_H
#define DBASEFOLDER_H

#include <QObject>
//db header
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>


#include <QObject>

class dbasefolder : public QObject
{
    Q_OBJECT

public:
    explicit dbasefolder(QObject *parent = nullptr);

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString personname READ personname WRITE setPersonname NOTIFY personnameChanged)
    Q_PROPERTY(QString personid READ personid WRITE setPersonid NOTIFY personidChanged)
    Q_PROPERTY(QString bookname READ bookname WRITE setBookname NOTIFY booknameChanged)
    Q_PROPERTY(QString bookauthor READ bookauthor WRITE setBookauthor NOTIFY bookauthorChanged)

    Q_PROPERTY(QStringList updateid READ updateid WRITE setUpdateid NOTIFY updateidChanged)
    Q_PROPERTY(QStringList updatepersonname READ updatepersonname WRITE setUpdatepersonname NOTIFY updatepersonnameChanged)
    Q_PROPERTY(QStringList updatepersonid READ updatepersonid WRITE setUpdatepersonid NOTIFY updatepersonidChanged)
    Q_PROPERTY(QStringList updatebookname READ updatebookname WRITE setUpdatebookname NOTIFY updatebooknameChanged)
    Q_PROPERTY(QStringList updatebookauthor READ updatebookauthor WRITE setUpdatebookauthor NOTIFY updatebookauthorChanged)

    Q_PROPERTY(QStringList deleteid READ deleteid WRITE setDeleteid NOTIFY deleteidChanged)


    Q_INVOKABLE QStringList mgetId();
    Q_INVOKABLE void msetId(QString id);
    Q_INVOKABLE QStringList mgetPersonname();
    Q_INVOKABLE void msetPersonname(QString personname);
    Q_INVOKABLE QStringList mgetPersonid();
    Q_INVOKABLE void msetPersonid(QString personid);
    Q_INVOKABLE QStringList mgetBookname();
    Q_INVOKABLE void msetBookname(QString bookname);
    Q_INVOKABLE QStringList mgetBookauthor();
    Q_INVOKABLE void msetBookauthor(QString bookauthor);


    Q_INVOKABLE void msubmit(QString personname,QString personid,QString bookname,QString bookauthor);
    Q_INVOKABLE void mread();
    Q_INVOKABLE void mupdate(QString id,QString personname,QString personid,QString bookname,QString bookauthor);
    Q_INVOKABLE void mdelete(int id);

    QStringList mid;
    QStringList mpersonname;
    QStringList mpersonid;
    QStringList mbookname;
    QStringList mbookauthor;

     QSqlDatabase db;

     const QString id() const;
     void setId(const QString &newId);

     const QString personname() const;
     void setPersonname(const QString &newPersonname);

     const QString personid() const;
     void setPersonid(const QString &newPersonid);

     const QString bookname() const;
     void setBookname(const QString &newBookname);

     const QString bookauthor() const;
     void setBookauthor(const QString &newBookauthor);



     const QStringList updateid() const;
     void setUpdateid(const QStringList &newUpdateid);

     const QStringList updatepersonname() const;
     void setUpdatepersonname(const QStringList &newUpdatepersonname);

     const QStringList updatepersonid() const;
     void setUpdatepersonid(const QStringList &newUpdatepersonid);

     const QStringList updatebookname() const;
     void setUpdatebookname(const QStringList &newUpdatebookname);

     const QStringList updatebookauthor() const;
     void setUpdatebookauthor(const QStringList &newUpdatebookauthor);

signals:

     void idChanged();
     void personnameChanged();
     void personidChanged();
     void booknameChanged();
     void bookauthorChanged();


     void updateidChanged();

     void updatepersonnameChanged();

     void updatepersonidChanged();

     void updatebooknameChanged();

     void updatebookauthorChanged();

private:
     QString m_id;
     QString m_personname;
     QString m_personid;
     QString m_bookname;
     QString m_bookauthor;


     QStringList m_updateid;
     QStringList m_updatepersonname;
     QStringList m_updatepersonid;
     QStringList m_updatebookname;
     QStringList m_updatebookauthor;
};

#endif // DBASEFOLDER_H
