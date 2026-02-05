#include "jsonparser.h"

JsonParser::JsonParser() {}

Query JsonParser::toQuery(const QByteArray &array)
{
    QJsonDocument doc = QJsonDocument::fromJson(array);

    if(doc.isEmpty()){
        return Query("");
    }

    QJsonArray jArray = doc.object()["persons"].toArray();

    QList<Person> persons;

    for(const QJsonValue& val : jArray){
        QJsonObject obj = val.toObject();
        persons.append(Person(obj["Id"].toInt(), obj["Name"].toString(), obj["Address"].toString(), obj["Phone"].toString()));
    }

    return Query(doc.object()["query"].toString(), persons);
}

QByteArray JsonParser::toByteArray(const Query& query)
{
    QJsonObject obj;
    QJsonArray personsJ;

    for(const auto& person : query.getPersons()){
        QJsonObject personJ;
        personJ["Id"] = person.id();
        personJ["Name"] = person.name();
        personJ["Address"] = person.address();
        personJ["Phone"] = person.phone();
        personsJ.append(personJ);
    }

    obj["query"] = query.getRequest();
    obj["persons"] = personsJ;

    QJsonDocument doc(obj);

    return doc.toJson(QJsonDocument::Compact);
}
