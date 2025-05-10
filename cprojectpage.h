#ifndef CPROJECTPAGE_H
#define CPROJECTPAGE_H

//#include <QWidget>
#include <QIcon>
#include <QListWidget>
#include <QMenu>
#include "qdomlite.h"

namespace Ui {
class CProjectPage;
}

class CProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit CProjectPage(QString path, bool quickStart = true, QString bgImagePath = QString(), QString extension = QString(), QWidget *parent = nullptr);
    ~CProjectPage();
    void setPath(const QString& path);
    void setDefultIcon(const QIcon& icon);
    void setExtension(const QString& ext);
    void setQuickStart(const bool qs);
    void setCustomProjects(const QStringList& l);
    void fillView();
    static QDomLiteDocument openFile(const QString& path, const QString& suffix = ".xml");
    static void saveFile(const QString&, QDomLiteDocument* Doc, QPixmap pix);
private:
    Ui::CProjectPage *ui;
    QPixmap createSquare(QPixmap p);
    QString m_Path;
    QIcon m_Icon;
    QString m_Ext;
    bool m_QuickStart;
    QMenu* m_Menu;
    QStringList m_CustomProjects;
signals:
    void openProjectTriggered(QString path);
    void newProjectTriggered();
    void quickStartTriggered();
private slots:
    void itemClicked(QListWidgetItem* i);
    void itemDoubleClicked(QListWidgetItem* i);
    void finishEditItem(QListWidgetItem* i);
    void showPopup(QPoint pos);
    void rename();
    void remove();
    void duplicate();
    void open();
};

#endif // CPROJECTPAGE_H
