#include "cframe.h"
#include "ui_cframe.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);

    Nombre = "Alumnos.xls";
    C = Li = 0;

    //ui->Le_Nombre->setDisabled(true);
    //ui->Le_Celular->setDisabled(true);
    //ui->RB_Exportar->setDisabled(true);
    //ui->Btn_Aceptar->setDisabled(true);
    ui->TW_Mostrar->setColumnCount(4);
    ui->TW_Disponible->setColumnCount(3);
    ui->TW_Mostrar->setHorizontalHeaderLabels(QStringList()<<"Libres"<<"Incio"<<"Fin"<<"Tamaño");
    ui->TW_Disponible->setHorizontalHeaderLabels(QStringList()<<"Inicio"<<"Fin"<<"Tamaño");
    //Menu();
    //Cargar();
    //MostrarC();
    setListas();
    MostrarListas();
    ui->RB_PrimerA->setChecked(true);
}

cframe::~cframe()
{
    delete ui;
}

void cframe::Cargar()
{
    ifstream Archivo(Nombre.data(),ios::in);
    string cuenta, nombre, celular;

    if(!Archivo){
        QMessageBox::critical(this,".:.Error.:.","NO fue Posible Abrir el Archivo!!!");
    }else{
        do{
            Archivo>>cuenta;
            Archivo>>nombre;
            Archivo>>celular;
            if(!Archivo.eof()){
                 F.Encolar(new alumno(cuenta, nombre, celular));
                 C++;
            }
        }while(!Archivo.eof());
    }
}

/*
void cframe::MostrarC()
{
    N = F.RaizPtr;
    ui->TW_Mostrar->setRowCount(C);
    for (int i=0; N!=0; i++, N=N->SigPtr) {
        QTableWidgetItem *cu = new QTableWidgetItem(QString::fromStdString(N->datos->getCuenta()));
        QTableWidgetItem *no = new QTableWidgetItem(QString::fromStdString(N->datos->getNombre()));
        QTableWidgetItem *ce = new QTableWidgetItem(QString::fromStdString(N->datos->getCelular()));
        ui->TW_Mostrar->setItem(i,0,cu);
        ui->TW_Mostrar->setItem(i,1,no);
        ui->TW_Mostrar->setItem(i,2,ce);
    }
}

void cframe::MostrarL()
{
    N = Disponibles.RaizPtr;
    ui->TW_Disponible->setRowCount(Li);
    for (int i=0; N!=0; i++, N=N->SigPtr) {
        QTableWidgetItem *cu = new QTableWidgetItem(QString::fromStdString(N->datos->getCuenta()));
        QTableWidgetItem *no = new QTableWidgetItem(QString::fromStdString(N->datos->getNombre()));
        QTableWidgetItem *ce = new QTableWidgetItem(QString::fromStdString(N->datos->getCelular()));
        ui->TW_Disponible->setItem(i,0,cu);
        ui->TW_Disponible->setItem(i,1,no);
        ui->TW_Disponible->setItem(i,2,ce);
    }
}
*/

void cframe::MostrarListas()
{
    N = L.RaizPtr;
    ui->TW_Mostrar->setRowCount(Di);
    ui->TW_Disponible->setRowCount(Oc);
    int Total = 0, DiC=0, OcC=0;
    for (int i=0; N!=0; i++, N=N->SigPtr) {
        if(N->datos->disponible){
            QTableWidgetItem *cu = new QTableWidgetItem(QString::fromStdString(N->datos->nombre));
            QTableWidgetItem *no = new QTableWidgetItem(QString::number(Total));
            Total += N->datos->tam;
            QTableWidgetItem *ce = new QTableWidgetItem(QString::number(Total - 1));
            QTableWidgetItem *ta = new QTableWidgetItem(QString::number(N->datos->tam));
            ui->TW_Mostrar->setItem(DiC,0,cu);
            ui->TW_Mostrar->setItem(DiC,1,no);
            ui->TW_Mostrar->setItem(DiC,2,ce);
            ui->TW_Mostrar->setItem(DiC,3,ta);
            DiC++;
        }else{
            QTableWidgetItem *no = new QTableWidgetItem(QString::number(Total));
            Total += N->datos->tam;
            QTableWidgetItem *ce = new QTableWidgetItem(QString::number(Total - 1));
            QTableWidgetItem *ta = new QTableWidgetItem(QString::number(N->datos->tam));

            ui->TW_Disponible->setItem(OcC,0,no);
            ui->TW_Disponible->setItem(OcC,1,ce);
            ui->TW_Disponible->setItem(OcC,2,ta);
            OcC++;
        }

    }
}

void cframe::setListas()
{

    L.insertarAlFrente(new model("a",100,true));
    L.insertarAlFinal(new model("",100,false));
    L.insertarAlFinal(new model("b",200,true));
    L.insertarAlFinal(new model("",100,false));
    L.insertarAlFinal(new model("c",75,true));
    L.insertarAlFinal(new model("d",125,true));
    L.insertarAlFinal(new model("",150,false));
    L.insertarAlFinal(new model("e",50,true));
    L.insertarAlFinal(new model("f",100,true));
    Di=6;
    Oc=3;
}


void cframe::Menu()
{
    M = QInputDialog::getText(this,".:.Menú.:.","1.-> Insertar Orden Creciente.\n"
                                                "2.-> Insertar Orden Decreciente.\n"
                                                "3.-> Insertar 3ra Posición.\n"
                                                "4.-> Insertar Antes de:\n"
                                                "5.-> Insertar Despues de:\n"
                                                "6.-> Insertar al Inicio.\n"
                                                "7.-> Insertar en Penultima.\n"
                                                "8.-> Insertar al Final.\n").toStdString().c_str()[0];
}


void cframe::on_Btn_Aceptar_clicked()
{

    /*
    if(ui->RB_Exportar->isChecked()){
        ofstream Archivo(Nombre.data(),ios::out|ios::app);

        if(!Archivo){
            QMessageBox::critical(this,".:.Error.:.","NO fue Posible Crear el Archivo!!!");
        }else{
            Archivo<<ui->Le_Cuenta->text().toStdString()<<"\t"
                  <<ui->Le_Nombre->text().toStdString()<<"\t"
                 <<ui->Le_Celular->text().toStdString()<<"\n";
            Archivo.close();
            QMessageBox::information(this,".:.Éxito.:.","Su Archivo ha sido creado y guardado Exitosamente!!!");
            F.Encolar(new alumno(ui->Le_Cuenta->text().toStdString(),ui->Le_Nombre->text().toStdString(), ui->Le_Celular->text().toStdString()));
            C++;
            ui->Le_Cuenta->clear();
            ui->Le_Nombre->clear();
            ui->Le_Celular->clear();
            ui->TW_Mostrar->clearContents();
            //MostrarC();
        }
    }else if(ui->RB_EliminaRaiz->isChecked()){
        F.Desencolar(A);
        //L.insertarEnPenultimo(A);
        C--;
        Li++;
        //MostrarC();
        //MostrarL();
        QMessageBox::critical(this,".:.","Le di Jabón a: "
                              + QString::fromStdString(A->getCuenta()) + " "
                              + QString::fromStdString(A->getNombre()) + " "
                              + QString::fromStdString(A->getCelular()));
    }
*/
}



void cframe::on_RB_Exportar_clicked()
{
    //ui->Btn_Aceptar->setEnabled(true);
}


void cframe::on_RB_EliminaRaiz_clicked()
{
   // ui->Btn_Aceptar->setEnabled(true);
}


void cframe::on_Le_Cuenta_textChanged(const QString &arg1)
{
   // ui->Le_Nombre->setEnabled(true);
}


void cframe::on_Le_Nombre_textChanged(const QString &arg1)
{
    //ui->Le_Celular->setEnabled(true);
}


void cframe::on_Le_Celular_textChanged(const QString &arg1)
{
    //ui->RB_Exportar->setEnabled(true);
    //ui->RB_EliminaRaiz->setEnabled(true);
}

void cframe::asignarBloque(int Byte){
    N = L.RaizPtr;
    bool SeHizo = false;
    for(int i=0; N!=0; i++, N=N->SigPtr){
        if(N->datos->disponible){
            if(Byte <= N->datos->tam){
                N->datos->disponible = false;
                Di--;
                Oc++;
                MostrarListas();
                QMessageBox::information(this,".:.Éxito.:.","Se ha ingresado correctamente!!!");
                return;
            }
        }
    }
    if(!SeHizo){
        QMessageBox::critical(this,".:.Error.:.","No hay bloque disponible para esa cantidad de Bytes!!!");
    }
}

void cframe::on_Btn_Asignar_clicked()
{
    if(ui->Sb_Bytes->value() != 0){
        if(ui->RB_PrimerA->isChecked()){
            asignarBloque(ui->Sb_Bytes->value());

        }


        ui->Sb_Bytes->setValue(0);
    }else{
        QMessageBox::critical(this,".:.Error.:.","Esta intentando ingresar 0 BYTES!!!");
    }
}


void cframe::on_RB_MejorA_clicked()
{
    ui->RB_PrimerA->setChecked(false);

}


void cframe::on_RB_PrimerA_clicked()
{
    ui->RB_MejorA->setChecked(false);
}


void cframe::on_Btn_Reset_clicked()
{
    ui->RB_PrimerA->setChecked(true);
    ui->RB_MejorA->setChecked(false);
    setListas();
    MostrarListas();
}

