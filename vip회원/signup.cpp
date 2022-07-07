#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_lineEdit_returnPressed() // 아이디를 입력하고 enter를 누를 경우
{
    QString id; // 문자열 변수 선언
    id = ui->lineEdit->text(); // lineedit 첫번째에 입력한 것을 id라는 변수에 저장
    QSqlQuery query; // 쿼리문을 실행하기 위한 변수
    QString SQL; // 쿼리문을 넣기 위한 QString 변수 선언
    SQL="select count(*) FROM userTB WHERE userId = '"+id+"'"; // 쿼리문
    qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
    query.exec(SQL);  // 쿼리문 실행
    query.next(); // 쿼리문 실행결과 확인
    if(query.value(0).toString() == '1') // 중복된 아이디가 있는 경우
    {
        ui->label_5->setText("중복된 아이디입니다.");
    }
    else // 회원가입 할 수 있는 아이디의 경우
    {
        ui->label_5->setText("회원가입 할 수 있는 아이디입니다.");
    }
}

void signup::on_pushButton_clicked() // 중복확인 버튼을 눌렀을 경우
{
    on_lineEdit_returnPressed();
}

void signup::on_lineEdit_3_textChanged()
{
    QString pw, checkpw; // 문자열 변수 선언
    pw = ui->lineEdit_2->text(); // 비밀번호 입력되어있는 것을 변수에 저장
    checkpw = ui->lineEdit_3->text(); // 비밀번호확인란에 입력 되어있는 값을 저장
    if(pw == checkpw) // 비밀번호가 일치할 경우
    {
        ui->label_6->setText("비밀번호가 일치합니다.");
    }
    else
    {
        ui->label_6->setText("비밀번호가 일치하지 않습니다.");
    }
}

void signup::on_pushButton_2_clicked()
{
    ui->label_7->setStyleSheet("QLabel { color : red; }"); // 색깔 빨갛게
    if(ui->label_5->text() != "회원가입 할 수 있는 아이디입니다.") // 중복확인이 안 된 경우
    {
        ui->label_7->setText("아이디 중복확인을 하십시오.");
    }
    else if(ui->label_6->text() != "비밀번호가 일치합니다.") // 비밀번호 확인이 안 된 경우
    {
        ui->label_7->setText("비밀번호가 일치하지 않습니다.");
    }
    else
    {
        QSqlQuery query; // 쿼리문을 실행하기 위한 변수
        QString SQL; // 쿼리문을 넣기 위한 QString 변수 선언
        SQL="insert into userTB values ('"+ui->lineEdit->text()+"', '"+ui->lineEdit_2->text()+"', '"+ui->lineEdit_4->text()+"')"; // 쿼리문
        qDebug()<<SQL<<endl; // 쿼리문 확인용 출력문
        query.exec(SQL);  // 쿼리문 실행
        qDebug()<<"회원가입 완료"<<endl;
        this->close();
    }
}
