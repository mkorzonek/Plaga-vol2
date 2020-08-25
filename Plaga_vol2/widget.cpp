#include "widget.h"
#include "symulator.h"
#include "ui_widget.h"
#include <math.h>
#include <windows.h>

Symulator symulacja;
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(next_day()));
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pb_start_clicked()
{
    symulacja.Fstart();
    //Fwczytaj();
    Finfoswiat();
    ui->stackedWidget->setCurrentIndex(0);
    ui->pb_start_time->setEnabled(0);
    ui->pb_stop_time->setEnabled(0);
    ui->pb_fast_time->setEnabled(0);
    symulacja.wirus.czas_inkubacji=ui->sp_czas_inkubacji->value();
    date.setDate(2020,1,1);

}

void Widget::on_pb_Ziemia_clicked()
{
    symulacja.obecny_kraj=200;
    Finfoswiat();
}


void Widget::on_pb_Polska_clicked()
{

    symulacja.obecny_kraj=0;
    firstclick();
    Finfo(symulacja.obecny_kraj);
}
void Widget::on_pb_Niemcy_clicked()
{
    symulacja.obecny_kraj=1;
    firstclick();
    Finfo(symulacja.obecny_kraj);
}

void Widget::next_day()
{
    symulacja.Fnext_day();
    Finfo(symulacja.obecny_kraj);
    date=date.addDays(1);
    ui->dateEdit->setDate(date);
}

void Widget::on_pb_stop_time_clicked()
{
    timer->stop();
}
void Widget::on_pb_start_time_clicked()
{
    timer->start(3000);
}
void Widget::on_pb_fast_time_clicked()
{
    timer->start(1000)  ;
}


void Widget::on_pb_gryzonie_1_toggled(bool checked)
{
    symulacja.wirus.gryzonie_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_gryzonie_2_toggled(bool checked)
{
    symulacja.wirus.gryzonie_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_ptaki_1_toggled(bool checked)
{
    symulacja.wirus.ptaki_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_ptaki_2_toggled(bool checked)
{
    symulacja.wirus.ptaki_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_zw_gospod_1_toggled(bool checked)
{
    symulacja.wirus.zw_gospodarcze_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_zw_gospod_2_toggled(bool checked)
{
    symulacja.wirus.zw_gospodarcze_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_woda_1_toggled(bool checked)
{
    symulacja.wirus.woda_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_woda_2_toggled(bool checked)
{
    symulacja.wirus.woda_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_powietrze_1_toggled(bool checked)
{
    symulacja.wirus.powietrze_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_powietrze_2_toggled(bool checked)
{
    symulacja.wirus.powietrze_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_krew_1_toggled(bool checked)
{
    symulacja.wirus.krew_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_krew_2_toggled(bool checked)
{
    symulacja.wirus.krew_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_owady_1_toggled(bool checked)
{
    symulacja.wirus.owady_1=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_pb_owady_2_toggled(bool checked)
{
    symulacja.wirus.owady_2=checked;
    symulacja.Fwsp_zar();
    Finfo(symulacja.obecny_kraj);
}

void Widget::on_sp_temp_rozw_max_valueChanged(int arg1)
{
    symulacja.wirus.temp_rozw_max=arg1;
    symulacja.Fwsp_zar();
}

void Widget::on_sp_temp_rozw_min_valueChanged(int arg1)
{
    symulacja.wirus.temp_rozw_min=arg1;
    symulacja.Fwsp_zar();
}

void Widget::on_sp_temp_latencji_max_valueChanged(int arg1)
{
    symulacja.wirus.temp_latencji_max=arg1;
    symulacja.Fwsp_zar();
}

void Widget::on_sp_temp_latencji_min_valueChanged(int arg1)
{
    symulacja.wirus.temp_latencji_min=arg1;
    symulacja.Fwsp_zar();
}

void Widget::on_sp_temp_zycia_max_valueChanged(int arg1)
{
    symulacja.wirus.temp_zycia_max=arg1;
    symulacja.Fwsp_zar();
}

void Widget::on_sp_temp_zycia_min_valueChanged(int arg1)
{
    symulacja.wirus.temp_zycia_min=arg1;
    symulacja.Fwsp_zar();
}

void Widget::on_sp_odp_leki_valueChanged(int arg1)
{
    symulacja.wirus.odp_leki=arg1;
}

void Widget::on_sp_czas_inkubacji_valueChanged(int arg1)
{
    symulacja.wirus.czas_inkubacji=arg1;
    symulacja.Fwsp_zar();
}

void Widget::firstclick()
{
    if(symulacja.pacjent_0==1)
    {
        symulacja.Ffirstclick();
        ui->pb_fast_time->setEnabled(1);
        ui->pb_start_time->setEnabled(1);
        ui->pb_stop_time->setEnabled(1);
        timer->start(3000);
    }
}

void Widget::Finfo(int i)
{
    if(i==200)
    {
        Finfoswiat();
    }
    else
    {
        QString str = QString::fromStdString(symulacja.k[i].nazwa);
        ui->l_nazwa_kraju->setText("Nazwa kraju: " + str);

        QString s = QString::number(symulacja.k[i].tablica.populacja[symulacja.k[i].dzien_zarazy]);
        ui->l_populacja->setText("Populacja: " + s);

        s = QString::number(symulacja.k[i].tablica.zdrowych[symulacja.k[i].dzien_zarazy]);
        ui->l_zdrowych->setText("Zdrowych: " + s);

        s = QString::number(symulacja.k[i].tablica.chorych[symulacja.k[i].dzien_zarazy]);
        ui->l_chorych->setText("Chorych: " + s);

        s = QString::number(symulacja.k[i].tablica.dziennie_zarazonych[symulacja.k[i].dzien_zarazy]);
        ui->l_dziennie_zarazonych->setText("Dziennie Zarażonych: " + s);

        s = QString::number(symulacja.k[i].tablica.dziennie_uzdrowionych[symulacja.k[i].dzien_zarazy]);
        ui->l_dziennie_uzdrowionych->setText("Dziennie Uzdrowionych: " + s);

        s = QString::number(symulacja.k[i].wsp_zar);
        ui->l_wsp_zarazania->setText("Wsp. zarażania: " + s);

        s = QString::number(symulacja.k[i].dzien_zarazy);
        ui->l_dzien_zarazy->setText("Dzień Zarazy: " + s);
    }
}

void Widget::Finfoswiat()
{
    QString str = QString::fromStdString(symulacja.ziemia.nazwa);
    ui->l_nazwa_kraju->setText(str);

    QString s = QString::number(symulacja.ziemia.tablica.populacja[symulacja.ziemia.dzien_zarazy]);
    ui->l_populacja->setText("Populacja: " + s);

    s = QString::number(symulacja.ziemia.tablica.zdrowych[symulacja.ziemia.dzien_zarazy]);
    ui->l_zdrowych->setText("Zdrowych: " + s);

    s = QString::number(symulacja.ziemia.tablica.chorych[symulacja.ziemia.dzien_zarazy]);
    ui->l_chorych->setText("Chorych: " + s);

    s = QString::number(symulacja.ziemia.tablica.dziennie_zarazonych[symulacja.ziemia.dzien_zarazy]);
    ui->l_dziennie_zarazonych->setText("Dziennie Zarażonych: " + s);

    s = QString::number(symulacja.ziemia.tablica.dziennie_uzdrowionych[symulacja.ziemia.dzien_zarazy]);
    ui->l_dziennie_uzdrowionych->setText("Dziennie Uzdrowionych: " + s);

    ui->l_wsp_zarazania->setText("");

    s = QString::number(symulacja.ziemia.dzien_zarazy);
    ui->l_dzien_zarazy->setText("Dzień Zarazy: " + s);
}

void Widget::on_pb_powrot_menu_start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pb_start_time->setEnabled(0);
    ui->pb_stop_time->setEnabled(0);
    ui->pb_fast_time->setEnabled(0);

    on_pb_gryzonie_1_toggled(0);
    ui->pb_gryzonie_1->setChecked(0);
    on_pb_gryzonie_2_toggled(0);
    ui->pb_gryzonie_2->setChecked(0);

    on_pb_ptaki_1_toggled(0);
    ui->pb_ptaki_1->setChecked(0);
    on_pb_ptaki_2_toggled(0);
    ui->pb_ptaki_2->setChecked(0);

    on_pb_zw_gospod_1_toggled(0);
    ui->pb_zw_gospod_1->setChecked(0);
    on_pb_zw_gospod_2_toggled(0);
    ui->pb_zw_gospod_2->setChecked(0);

    on_pb_woda_1_toggled(0);
    ui->pb_woda_1->setChecked(0);
    on_pb_woda_2_toggled(0);
    ui->pb_woda_2->setChecked(0);

    on_pb_powietrze_1_toggled(0);
    ui->pb_powietrze_1->setChecked(0);
    on_pb_powietrze_2_toggled(0);
    ui->pb_powietrze_2->setChecked(0);

    on_pb_krew_1_toggled(0);
    ui->pb_krew_1->setChecked(0);
    on_pb_krew_2_toggled(0);
    ui->pb_krew_2->setChecked(0);

    on_pb_owady_1_toggled(0);
    ui->pb_owady_1->setChecked(0);
    on_pb_owady_2_toggled(0);
    ui->pb_owady_2->setChecked(0);

    timer->stop();


}

Widget::~Widget()
{
    symulacja.~Symulator();
    ;
    delete ui;
}


void Widget::Fwczytaj()
{
    ui->sp_temp_rozw_max->setValue(symulacja.wirus.temp_rozw_max);
    ui->sp_temp_rozw_min->setValue(symulacja.wirus.temp_rozw_min);
    ui->sp_temp_latencji_max->setValue(symulacja.wirus.temp_latencji_max);
    ui->sp_temp_latencji_min->setValue(symulacja.wirus.temp_latencji_min);
    ui->sp_temp_zycia_max->setValue(symulacja.wirus.temp_zycia_max);
    ui->sp_temp_zycia_min->setValue(symulacja.wirus.temp_zycia_min);
    ui->sp_odp_leki->setValue(symulacja.wirus.odp_leki);
    ui->sp_czas_inkubacji->setValue(symulacja.wirus.czas_inkubacji);

}
void Widget::on_pb_zaraz_clicked()
{

}
