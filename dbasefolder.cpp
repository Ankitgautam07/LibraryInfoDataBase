#include "dbasefolder.h"
#include <QDebug>
#include <QDir>

QString p_id;
QString p_personname;
QString p_personid;
QString p_bookname;
QString p_bookauthor;
QString lastInsertRowId;
int dbflag = 0;


dbasefolder::dbasefolder(QObject *parent) : QObject(parent)
{
    //==================DB Connection ========================

    if(!dbflag){   //will run once
        const QString DRIVER("QSQLITE");

        if(QSqlDatabase ::isDriverAvailable(DRIVER)){
            qDebug()<<DRIVER<<" available";
        }else
            qDebug()<<DRIVER<<" not available";

        db = QSqlDatabase::addDatabase(DRIVER);

        qDebug()<<QDir::currentPath();

        //============= create db path ===================
        QString dbDir = "mkdir "+ QDir::currentPath() +"/db/";
        QString dbPath = QDir::currentPath() +"/db/mydatabase.db";
        //qDebug()<<"dbPath  : "<<dbPath;
        QFile file(dbPath);

        if(!file.exists()){
            int sysret = system(dbDir.toStdString().c_str());
            qDebug()<<"sysret  : "<<sysret;

            if(sysret !=0)
            {
                qDebug("DB Path Create error....");
            }
            qDebug("DB Path Created....");
        }
        else
            qDebug("DB Path Exist !");
        //====================================
        db.setDatabaseName( QDir::currentPath() +"/db/mydatabase.db"); //your db in project directory,
        //uncheck shadow build in projects
        if(!db.open())
            qWarning() << "ERROR: " << db.lastError();
        else
            qDebug()<<" db open success";

        dbflag = 1;
    }
    //===================================================================================

    //QSqlQuery query1("DROP TABLE people");
    QSqlQuery query("CREATE TABLE IF NOT EXISTS library (id INTEGER PRIMARY KEY, personname TEXT, personid TEXT,bookname TEXT,bookauthor TEXT)");

    if(!query.isActive())
        qWarning() << "ERROR: " << query.lastError().text();

    query.clear();

    mread();


    //========================================================
}



void dbasefolder::msubmit(QString personname,QString personid,QString bookname,QString bookauthor)
{
    qDebug() <<"==> C++ : "<<personname <<" : "<<personid <<" :"<<bookname<<":"<<bookauthor;

    QSqlQuery query;

    query.prepare("SELECT id FROM library WHERE id = (SELECT MAX(id) FROM library);");

    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    while(query.next())
    {
        lastInsertRowId = query.value(0).toString();
        qDebug()<<"lastInsertRowId ===============================> "<<lastInsertRowId;

    }
    query.clear();
    //-------------------------------------------------
    int row_id = lastInsertRowId.toInt();
    row_id++;
    lastInsertRowId = QString::number(row_id);
    //--------------------------------------------------
    //============ db insert record ==================
    qDebug()<<"db insertion =========================> ";

    qDebug()<<"INSERT INTO library (id,personname,personid,bookname,bookauthor) VALUES('"+lastInsertRowId+"','"+personname+"','"+personid+"','"+bookname+"','"+bookauthor+"'"+")";

    if(!query.exec("INSERT INTO library(id,personname,personid,bookname,bookauthor) VALUES('"+lastInsertRowId+"','"+personname+"','"+personid+"','"+bookname+"','"+bookauthor+"'"+")"))
        qWarning() << "ERROR: " << query.lastError().text();
    //===============================================

}
void dbasefolder::mupdate(QString id,QString m_personname,QString m_personid,QString m_bookname,QString m_bookauthor)

{
    //============ db update record ==================
    qDebug()<<"db Update =========================> ";

    qDebug()<<"UPDATE library SET personname ='"+m_personname+"',personid ="+m_personid+",bookname ="+m_bookname+",bookauthor ="+m_bookauthor+" WHERE id ="+id;

    QSqlQuery query;
    if(!query.exec("UPDATE library SET personname ='"+m_personname+"',personid ="+m_personid+",bookname ="+m_bookname+",bookauthor ="+m_bookauthor+" WHERE id ="+id))
        qWarning() << "ERROR: " << query.lastError().text();
    //===============================================

}
void dbasefolder::mread()
{
    qDebug()<<"mread called.......";

    mid.clear();
    mpersonname.clear();
    mpersonid.clear();
    mbookname.clear();
    mbookauthor.clear();

    QSqlQuery query;
    query.prepare("SELECT id, personname, personid,bookname,bookauthor FROM library Order by id DESC;");
    if(!query.exec())
        qWarning() << "ERROR: " << query.lastError().text();

    while(query.next())
    {
        p_id = query.value(0).toString();
        p_personname = query.value(1).toString();
        p_personid = query.value(2).toString();
        p_bookname = query.value(3).toString();
        p_bookauthor = query.value(4).toString();

        qDebug()<<"======================================";
        qDebug()<<"p_id : "<<p_id;
        qDebug()<<"p_companyname : "<<p_personname;
        qDebug()<<"p_companyid : "<<p_personid;
        qDebug()<<"p_companyrole : "<<p_bookname;
        qDebug()<<"p_companyrole : "<<p_bookauthor;
        qDebug()<<"======================================";

        msetId(p_id);
        msetPersonname(p_personname);
        msetPersonid(p_personid);
        msetBookname(p_bookname);
        msetBookauthor(p_bookauthor);
    }
}
void dbasefolder::mdelete(int id)
{
    //============ db delete record ==================
    qDebug()<<"db delete record =========================> ";

    qDebug()<<"DELETE FROM library WHERE id = "+QString::number(id);

    QSqlQuery query;
    if(!query.exec("DELETE FROM library WHERE id = "+QString::number(id)))
        qWarning() << "ERROR: " << query.lastError().text();
    //===============================================
}

QStringList dbasefolder::mgetId()
{
    return mid;
}

void dbasefolder::msetId(QString id)
{
    mid<<id;
    setUpdateid(mid);
}

QStringList dbasefolder::mgetPersonname()
{
    return mpersonname;
}

void dbasefolder::msetPersonname(QString personname)
{
    mpersonname <<personname;

    setUpdatepersonname(mpersonname);
}

QStringList dbasefolder::mgetPersonid()
{
    return mpersonid;
}

void dbasefolder::msetPersonid(QString personid)
{
    mpersonid <<personid;

    setUpdatepersonid(mpersonid);
}

QStringList dbasefolder::mgetBookname()
{
    return mbookname;
}

void dbasefolder::msetBookname(QString bookname)
{
    mbookname <<bookname;

    setUpdatebookname(mbookname);
}

QStringList dbasefolder::mgetBookauthor()
{
    return mbookauthor;
}

void dbasefolder::msetBookauthor(QString bookauthor)
{
    mbookauthor <<bookauthor;

    setUpdatebookauthor(mbookauthor);
}



const QString dbasefolder::id() const
{
    return m_id;
}

void dbasefolder::setId(const QString &newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

const QString dbasefolder::personname() const
{
    return m_personname;
}

void dbasefolder::setPersonname(const QString &newPersonname)
{
    if (m_personname == newPersonname)
        return;
    m_personname = newPersonname;
    emit personnameChanged();
}

const QString dbasefolder::personid() const
{
    return m_personid;
}

void dbasefolder::setPersonid(const QString &newPersonid)
{
    if (m_personid == newPersonid)
        return;
    m_personid = newPersonid;
    emit personidChanged();
}

const QString dbasefolder::bookname() const
{
    return m_bookname;
}

void dbasefolder::setBookname(const QString &newBookname)
{
    if (m_bookname == newBookname)
        return;
    m_bookname = newBookname;
    emit booknameChanged();
}

const QString dbasefolder::bookauthor() const
{
    return m_bookauthor;
}

void dbasefolder::setBookauthor(const QString &newBookauthor)
{
    if (m_bookauthor == newBookauthor)
        return;
    m_bookauthor = newBookauthor;
    emit bookauthorChanged();
}


const QStringList dbasefolder::updateid() const
{
    return m_updateid;
}

void dbasefolder::setUpdateid(const QStringList &newUpdateid)
{
    if (m_updateid == newUpdateid)
        return;
    m_updateid = newUpdateid;
    emit updateidChanged();
}

const QStringList dbasefolder::updatepersonname() const
{
    return m_updatepersonname;
}

void dbasefolder::setUpdatepersonname(const QStringList &newUpdatepersonname)
{
    if (m_updatepersonname == newUpdatepersonname)
        return;
    m_updatepersonname = newUpdatepersonname;
    emit updatepersonnameChanged();
}

const QStringList dbasefolder::updatepersonid() const
{
    return m_updatepersonid;
}

void dbasefolder::setUpdatepersonid(const QStringList &newUpdatepersonid)
{
    if (m_updatepersonid == newUpdatepersonid)
        return;
    m_updatepersonid = newUpdatepersonid;
    emit updatepersonidChanged();
}

const QStringList dbasefolder::updatebookname() const
{
    return m_updatebookname;
}

void dbasefolder::setUpdatebookname(const QStringList &newUpdatebookname)
{
    if (m_updatebookname == newUpdatebookname)
        return;
    m_updatebookname = newUpdatebookname;
    emit updatebooknameChanged();
}

const QStringList dbasefolder::updatebookauthor() const
{
    return m_updatebookauthor;
}

void dbasefolder::setUpdatebookauthor(const QStringList &newUpdatebookauthor)
{
    if (m_updatebookauthor == newUpdatebookauthor)
        return;
    m_updatebookauthor = newUpdatebookauthor;
    emit updatebookauthorChanged();
}
