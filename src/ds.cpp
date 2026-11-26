#include "ds.h"

QString getUnique(const QString& str) {
    QString res; res.reserve(str.size());
    QSet<QChar> seen;
    for (const QChar& ch : str) {
        if (!seen.contains(ch)) {
            seen.insert(ch);
            res.append(ch);
        }
    }
    return res;
}