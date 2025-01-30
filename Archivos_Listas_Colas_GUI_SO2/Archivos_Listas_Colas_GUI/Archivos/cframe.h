/*Oscar**
 * Edgar**
 * Ana**
 * Alex**
 * Valeria**
 * Alejandro**
 */
#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <fstream>
#include <QInputDialog>
#include <QMessageBox>
//#include <vector>
#include <alumno.h>
#include <cola.h>
#include <model.h>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();
    void Cargar();
    void MostrarC();
    void MostrarL();
    void MostrarListas();
    void setListas();
    void asignarBloque(int Byte);
    void Menu();

private slots:
    void on_Btn_Aceptar_clicked();
    void on_RB_Exportar_clicked();
    void on_Le_Cuenta_textChanged(const QString &arg1);
    void on_Le_Nombre_textChanged(const QString &arg1);
    void on_Le_Celular_textChanged(const QString &arg1);
    void on_RB_EliminaRaiz_clicked();

    void on_Btn_Asignar_clicked();

    void on_RB_MejorA_clicked();

    void on_RB_PrimerA_clicked();

    void on_Btn_Reset_clicked();

private:

    //lista <model<alumno*>> Disponibles;
    //lista <model<alumno*>> Ocupados;
    //nodo <model<alumno*>> *N;
    //int Di, Oc;

    lista<model*> L;
    nodo<model*>*N;
    int Di, Oc;

    Ui::cframe *ui;
    string Nombre;
    //vector <alumno*> V;
    cola <alumno*> F;
    //lista <alumno*> L;
    //nodo <alumno*> *N;
    int C,Li;
    char M;
    alumno *A;
};
#endif // CFRAME_H
