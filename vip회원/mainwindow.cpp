#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "findinfo.h"
#include "menu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_2_returnPressed() // 사용자가 lineedit에서 enter를 입력했을 경우 동작 (로그인)
{
    QString id, pw; // 문자열 변수 선언
    id = ui->lineEdit->text(); // lineedit 첫번째에 입력한 것을 id라는 변수에 저장
    pw = ui->lineEdit_2->text(); // 두번째 lineedit에 입력한 내용을 pw라는 변수에 저장
    QSqlQuery query; // 쿼리문을 실행하기 위한 변수
    QString SQL; // 쿼리문을 넣기 위한 QString 변수 선언
    SQL="select count(*) FROM userTB WHERE userId = '"+id+"'"; // 쿼리문
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);  // 쿼리문 실행
    query.next(); // 쿼리문 실행결과 확인
    if(query.value(0).toString() == '0') // 해당하는 아이디가 없을 경우
    {
        ui->label_3->setText("등록되지 않은 아이디입니다.");
    }
    else // 해당하는 아이디가 존재할 경우
    {
        SQL="select count(*) FROM userTB WHERE userId = '"+id+"' and userPw = '"+pw+"'"; // 쿼리문
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);  // 쿼리문 실행
        query.next(); // 쿼리문 실행결과 확인
        if(query.value(0).toString() == '0') // 아이디는 맞지만 비밀번호가 틀릴 경우
        {
            ui->label_3->setText("비밀번호를 확인해주세요.");
        }
        else
        {
            SQL="select userRating FROM userTB WHERE userId = '"+id+"' and userPw = '"+pw+"'"; // 쿼리문
            qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
            query.exec(SQL);  // 쿼리문 실행
            query.next(); // 쿼리문 실행결과 확인
            if(query.value(0).toString() == "vip")
            {
                QMessageBox::information(nullptr,"Succsefull","VIP회원님 환영합니다.");
                ui->label_3->setText("로그인 성공.");
                this->close();
                menu userWindow(id); // 객체 생성
                userWindow.setModal(true); // 정보찾기창 열기
                userWindow.exec(); // 정보찾기창 닫으면
                this->show(); // 기존에 열렸던 창 다시 열기
            }
            else
                QMessageBox::information(nullptr,"Succsefull","VIP회원만 접속할 수 있습니다.");
        }
    }
}

void MainWindow::on_pushButton_clicked() // 회원가입 버튼을 눌렀을 경우
{
    qDebug()<<"회원가입"<<endl; // 함수 진입확인용 출력문
    this->close(); // 기존 창 닫기
    signup userWindow; // 객체 생성
    userWindow.setModal(true); // 회원가입 창 열기
    userWindow.exec(); // 회원가입 창 닫으면
    this->show(); // 기존에 열렸던 창 다시 열기
}

void MainWindow::on_pushButton_2_clicked() // 아이디 비밀번호 찾기 버튼을 눌렀을 경우
{
    qDebug()<<"아이디 비밀번호 찾기"<<endl; // 함수 진입확인용 출력문
    this->close(); // 기존 창 닫기
    findinfo userWindow; // 객체 생성
    userWindow.setModal(true); // 정보찾기창 열기
    userWindow.exec(); // 정보찾기창 닫으면
    this->show(); // 기존에 열렸던 창 다시 열기
}

void MainWindow::on_pushButton_3_clicked()
{
    on_lineEdit_2_returnPressed();
}
