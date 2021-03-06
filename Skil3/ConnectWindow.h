#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H
#include "SCService.h"
#include "Scientist.h"
#include "Computer.h"
#include "Utilities.h"
#include "Invented.h"
#include <QTableWidgetItem>
#include <QDialog>

namespace Ui
{
class ConnectWindow;
}

class ConnectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = 0);
    ~ConnectWindow();

private slots:
    void on_button_connectBack_clicked();

    void on_button_connectQuit_clicked();

    void on_input_connectScientistSearch_textChanged(const QString &arg1);

    void on_input_connectComputerSearch_textChanged(const QString &arg1);

    void on_button_connectScientistAndComputer_clicked();

    void on_table_connectScientistSearchResult_itemDoubleClicked(QTableWidgetItem *item);

    void on_table_connectComputerSearchResult_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::ConnectWindow *ui;
    vector<Scientist> _currentlyDisplayedScientists;
    vector<Computer> _currentlyDisplayedComputers;
    vector<Invented> _currentlyDisplayedConnections;
    SCService _scs;


    void displayScientistSearchResult(const QString &arg1);
    void displayComputerSearchResult(const QString &arg1);
    void displayAllCurrentConnections();

};

#endif // CONNECTWINDOW_H
