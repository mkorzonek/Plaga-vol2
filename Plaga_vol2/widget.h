#ifndef WIDGET_H
#define WIDGET_H

#include "symulator.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QTimer>
#include <QDateTime>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{

    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    friend class Symulator;
    QDateTime dateEdit;

    QDate date;

    QTimer *timer;

    QLayout *Layout_all;

    QPushButton *pb_Polska;

    QPushButton *pb_ptaki_0;
    QPushButton *pb_ptaki_1;
    QPushButton *pb_ptaki_2;
    QPushButton *pb_ptaki_3;

    QPushButton *pb_gryzonie_0;
    QPushButton *pb_gryzonie_1;
    QPushButton *pb_gryzonie_2;
    QPushButton *pb_gryzonie_3;

    QPushButton *pb_zw_gospodarcze_0;
    QPushButton *pb_zw_gospodarcze_1;
    QPushButton *pb_zw_gospodarcze_2;
    QPushButton *pb_zw_gospodarcze_3;



    QLabel *l_wybierz;
    QLabel *l_nazwa_kraju;
    QLabel *l_populacja;
    QLabel *l_zdrowych;
    QLabel *l_chorych;
    QLabel *l_dziennie_zarazonych;
    QLabel *l_dziennie_uzdrowionych;
    QLabel *l_dzien_zarazy;



    void Finfo(int n);
    void Finfoswiat();
    void Fwczytaj();
    void firstclick();


private slots:

    void next_day();

    void on_pb_Polska_clicked();
    void on_pb_Niemcy_clicked();


    void on_pb_start_clicked();


    void on_pb_start_time_clicked();
    void on_pb_stop_time_clicked();



    void on_pb_gryzonie_1_toggled(bool checked);

    void on_pb_gryzonie_2_toggled(bool checked);

    void on_pb_ptaki_1_toggled(bool checked);

    void on_pb_ptaki_2_toggled(bool checked);

    void on_pb_zw_gospod_1_toggled(bool checked);

    void on_pb_zw_gospod_2_toggled(bool checked);


    void on_pb_woda_1_toggled(bool checked);

    void on_pb_woda_2_toggled(bool checked);

    void on_pb_powietrze_1_toggled(bool checked);

    void on_pb_powietrze_2_toggled(bool checked);

    void on_pb_krew_1_toggled(bool checked);

    void on_pb_krew_2_toggled(bool checked);

    void on_pb_owady_1_toggled(bool checked);

    void on_pb_owady_2_toggled(bool checked);



    void on_pb_fast_time_clicked();

    void on_sp_temp_rozw_min_valueChanged(int arg1);

    void on_sp_temp_rozw_max_valueChanged(int arg1);

    void on_sp_temp_latencji_min_valueChanged(int arg1);

    void on_sp_temp_latencji_max_valueChanged(int arg1);

    void on_sp_temp_zycia_min_valueChanged(int arg1);

    void on_sp_temp_zycia_max_valueChanged(int arg1);

    void on_sp_odp_leki_valueChanged(int arg1);

    void on_sp_czas_inkubacji_valueChanged(int arg1);

    void on_pb_powrot_menu_start_clicked();

    void on_pb_Ziemia_clicked();

    void on_pb_zaraz_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
