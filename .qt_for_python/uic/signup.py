# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/signup.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_signup(object):
    def setupUi(self, signup):
        signup.setObjectName("signup")
        signup.resize(430, 512)
        self.label = QtWidgets.QLabel(signup)
        self.label.setGeometry(QtCore.QRect(80, 130, 51, 17))
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(signup)
        self.lineEdit.setGeometry(QtCore.QRect(130, 124, 151, 31))
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(signup)
        self.lineEdit_2.setGeometry(QtCore.QRect(130, 180, 151, 31))
        self.lineEdit_2.setEchoMode(QtWidgets.QLineEdit.Password)
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.label_2 = QtWidgets.QLabel(signup)
        self.label_2.setGeometry(QtCore.QRect(70, 186, 61, 17))
        self.label_2.setObjectName("label_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(signup)
        self.lineEdit_3.setGeometry(QtCore.QRect(130, 240, 151, 31))
        self.lineEdit_3.setEchoMode(QtWidgets.QLineEdit.Password)
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.label_3 = QtWidgets.QLabel(signup)
        self.label_3.setGeometry(QtCore.QRect(40, 246, 91, 17))
        self.label_3.setObjectName("label_3")
        self.lineEdit_4 = QtWidgets.QLineEdit(signup)
        self.lineEdit_4.setGeometry(QtCore.QRect(130, 300, 151, 31))
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.label_4 = QtWidgets.QLabel(signup)
        self.label_4.setGeometry(QtCore.QRect(90, 306, 31, 17))
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(signup)
        self.label_5.setGeometry(QtCore.QRect(130, 160, 151, 17))
        font = QtGui.QFont()
        font.setPointSize(8)
        self.label_5.setFont(font)
        self.label_5.setText("")
        self.label_5.setObjectName("label_5")
        self.pushButton = QtWidgets.QPushButton(signup)
        self.pushButton.setGeometry(QtCore.QRect(290, 130, 89, 25))
        font = QtGui.QFont()
        font.setFamily("Umpush")
        font.setBold(True)
        font.setWeight(75)
        self.pushButton.setFont(font)
        self.pushButton.setObjectName("pushButton")
        self.label_6 = QtWidgets.QLabel(signup)
        self.label_6.setGeometry(QtCore.QRect(130, 280, 151, 17))
        font = QtGui.QFont()
        font.setPointSize(8)
        self.label_6.setFont(font)
        self.label_6.setText("")
        self.label_6.setObjectName("label_6")
        self.pushButton_2 = QtWidgets.QPushButton(signup)
        self.pushButton_2.setGeometry(QtCore.QRect(160, 360, 89, 25))
        font = QtGui.QFont()
        font.setFamily("Umpush")
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_2.setFont(font)
        self.pushButton_2.setObjectName("pushButton_2")
        self.label_7 = QtWidgets.QLabel(signup)
        self.label_7.setGeometry(QtCore.QRect(130, 340, 151, 17))
        font = QtGui.QFont()
        font.setPointSize(8)
        self.label_7.setFont(font)
        self.label_7.setText("")
        self.label_7.setObjectName("label_7")

        self.retranslateUi(signup)
        QtCore.QMetaObject.connectSlotsByName(signup)

    def retranslateUi(self, signup):
        _translate = QtCore.QCoreApplication.translate
        signup.setWindowTitle(_translate("signup", "Dialog"))
        self.label.setText(_translate("signup", "아이디"))
        self.label_2.setText(_translate("signup", "비밀번호"))
        self.label_3.setText(_translate("signup", "비밀번호 확인"))
        self.label_4.setText(_translate("signup", "이름"))
        self.pushButton.setText(_translate("signup", "중복확인"))
        self.pushButton_2.setText(_translate("signup", "회원가입"))
