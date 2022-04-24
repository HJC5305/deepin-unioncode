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
    static QString toolKitName() { return "cmake"; }
    virtual bool configure(const QString &projectPath) override;
    virtual QStandardItem *createRootItem(const QString &projectPath, const QString &outputPath) override;
    virtual QMenu* createItemMenu(const QStandardItem *item) override;
private slots:
    void processReadAll();
    void processFinished(int code, QProcess::ExitStatus status);
    void actionTriggered();
private:
    QString cmakeBuildPath(const QString &cmakePath);

    // cmake CDT4 options
    QStandardItem *cdt4FindItem(QStandardItem *rootItem, QString &name);
    QStandardItem *cdt4FindParentItem(QStandardItem *rootItem, QString &name);
    QHash<QString, QString> cdt4Subporjects(QStandardItem *rootItem);
    QStandardItem *cdt4DisplayOptimize(QStandardItem *rootItem);
    void cdt4TargetsDisplayOptimize(QStandardItem *item, const QHash<QString, QString> &subprojectsMap);
    void cdt4SubprojectsDisplayOptimize(QStandardItem *item);
    QDomDocument cdt4LoadProjectXmlDoc(const QString &cmakePath);
    QDomDocument cdt4LoadMenuXmlDoc(const QString &cmakePath);
    QString cdt4FilePath(const QString &cmakePath);
};

#endif // CMAKEGENERATOR_H
