#include "findinfo.h"
#include "ui_findinfo.h"

findinfo::findinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findinfo)
{
    ui->setupUi(this);
}

findinfo::~findinfo()
{
    delete ui;
}

void findinfo::on_lineEdit_returnPressed() // 이름을 입력하고 enter를 쳤을 경우
{
    QString name, SQL; // 쿼리문을 넣기 위한 QString 변수 선언
    QSqlQuery query;
    name = ui->lineEdit->text();
    SQL="select count(*) FROM userTB WHERE userId = '"+name+"'"; // 쿼리문
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);  // 쿼리문 실행
    query.next(); // 쿼리문 실행결과 확인
    if(query.value(0).toString() == '0') // 등록된 정보가 없는 경우
    {
        ui->label_2->setText("등록되지 않은 사용자입니다.");
    }
    else
    {
        SQL="select userId, userPw FROM userTB WHERE userId = '"+name+"'"; // 쿼리문
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);  // 쿼리문 실행
        while(query.next()) // 쿼리문 실행결과 확인
        {
            QMessageBox::information(nullptr,"Succsefull","아이디:"+query.value(0).toString()+"\n비밀번호:"+query.value(1).toString()+""); // 정보메세지 박스로 아이디와 비밀번호 보여줌
            qDebug()<<query.value(0).toString()<<endl<<query.value(1).toString()<<endl; // 확인용 출력문
        }
    }
}

void findinfo::on_pushButton_clicked() // 찾기 버튼을 눌렀을 경우
{
    on_lineEdit_returnPressed();
}
