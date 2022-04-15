#ifndef CMAKEGENERATOR_H
#define CMAKEGENERATOR_H

#include "services/project/projectservice.h"

#include <QObject>
#include <QDomDocument>

class CMakeGenerator : public dpfservice::ProjectGenerator
{
    Q_OBJECT
    QProcess process;
public:
    explicit CMakeGenerator();
    virtual bool configure(const QString &projectPath) override;
    virtual QStandardItem *createRootItem(const QString &projectPath) override;
    virtual QMenu* createIndexMenu(const QModelIndex &index) override;
private slots:
    void processReadAll();
    void processFinished(int code, QProcess::ExitStatus status);
private:
    QString cmakeBuildPath(const QString &cmakePath);

    // cmake CDT4 options
    QStandardItem *cdt4FindItem(QStandardItem *rootItem, QString &name);
    QStandardItem *cdt4FindParentItem(QStandardItem *rootItem, QString &name);
    QHash<QString, QString> cdt4Subporjects(QStandardItem *rootItem);
    QStandardItem *cdt4DisplayOptimize(QStandardItem *rootItem);
    void cdt4TargetsDisplayOptimize(QStandardItem *item, const QHash<QString, QString> &subprojectsMap);
    void cdt4SubprojectsDisplayOptimize(QStandardItem *item);
    QDomDocument cdt4LoadXmlDoc(const QString &cmakePath);
    QString cdt4FilePath(const QString &cmakePath);
};

#endif // CMAKEGENERATOR_H