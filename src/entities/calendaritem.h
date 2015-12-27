#ifndef CALENDAR_ITEM_H
#define CALENDAR_ITEM_H

#include <QDateTime>
#include <QSqlQuery>
#include <QUrl>


class CalendarItem
{
public:
    explicit CalendarItem();

    int getId();
    bool getHasDirtyData();
    static bool addCalendarItem( QString name, QString fileName, QString text );
    static CalendarItem fetch( int id );
    static QList<CalendarItem> search(QString text);
    static CalendarItem calendarItemFromQuery( QSqlQuery query );
    bool store();
    friend QDebug operator<<(QDebug dbg, const CalendarItem &calendarItem);
    bool fileExists();
    bool exists();
    bool fillFromQuery(QSqlQuery query);
    bool fillByFileName(QString fileName);
    bool remove();
    bool isFetched();
    bool isCompleted();
    static CalendarItem fetchByUrlAndCalendar(QString url, QString calendar);
    static bool addCalendarItemForRequest(QString calendar, QUrl url, QString etag, QString lastModifiedString);
    static QList<CalendarItem> fetchAllByCalendar(QString calendar);
    static bool deleteAllByCalendar(QString calendar);
    QString getUrl();
    QString getSummary();
    QString getDescription();
    void setSummary(QString text);
    void setDescription(QString text);
    static bool setupTables();
    bool updateWithICSData(QString icsData);
    QString getUid();
    static CalendarItem fetchByUid(QString uid);
    int getPriority();
    QString generateNewICSData();
    QString getICSData();
    void setPriority(int value);
    void setICSData(QString text);
    QString getETag();
    QString getLastModifiedString();
    static CalendarItem fetchByUrl(QUrl url);
    void setLastModifiedString(QString text);
    void setETag(QString text);
    static QList<QUrl> fetchAllUrlsByCalendar(QString calendar);
    void setCalendar(QString text);
    static CalendarItem createNewTodoItem(QString summary, QString calendar);
    void setUrl(QUrl url);
    void setUid(QString text);
    void setModified(QDateTime dateTime);
    void setCreated(QDateTime dateTime);
private:
    int id;
    QString summary;
    QString url;
    QString description;
    QString calendar;
    QString uid;
    QString icsData;
    QString etag;
    QString lastModifiedString;
    int priority = 0;
    bool hasDirtyData;
    bool completed;
    QDateTime alarmDate;
    QDateTime created;
    QDateTime modified;
    QHash<QString, QString> icsDataHash;
    QStringList *icsDataKeyList;
    static QString decodeICSDataLine(QString line);
    static QString findFreeHashKey(QHash<QString, QString> *hash, QString key, int number = 0 );
    void generateICSDataHash();
    void updateICSDataKeyListFromHash();
};

#endif // CALENDAR_ITEM_H