#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <ParseDialog.h>
#include <Config.h>
#include "OutputParser.h"
#include "ConfigureCommandDialog.h"
#include "SimulationsObserver.h"
#include "ui_mainwindow.h"
#include "Simulator.h"
#include<QUuid>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_actionCreate_triggered();
    void refresh_on_signal_from_ovserver();

    void on_actionParse_scs_triggered();

    void on_actionParse_output_Sdat_triggered();

private:
    Ui::MainWindow *ui;
    QDir m_app_workspace;
    QString m_app_home_path;
    QList<Simulator*> m_SimulatorList;
    const QString DEFAULT_SCS_SRC;
    SimulationsObserver *m_sim_observer;

    void startObservingWorkspace();
    void prepareWorkspace();
    void populateSimulators(QStringList &s);
    void prepareWorkspaceDir();
    QStringList loadSimulatorListFromWorkspace();
};

#endif // MAINWINDOW_H
