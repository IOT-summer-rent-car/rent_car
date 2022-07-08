# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/login.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_login(object):
    def setupUi(self, login):
        login.setObjectName("login")
        login.resize(400, 300)
        self.lineEdit = QtWidgets.QLineEdit(login)
        self.lineEdit.setGeometry(QtCore.QRect(60, 30, 113, 25))
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(login)
        self.lineEdit_2.setGeometry(QtCore.QRect(60, 70, 113, 25))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.pushButton = QtWidgets.QPushButton(login)
        self.pushButton.setGeometry(QtCore.QRect(200, 70, 89, 25))
        self.pushButton.setObjectName("pushButton")

        self.retranslateUi(login)
        QtCore.QMetaObject.connectSlotsByName(login)

    def retranslateUi(self, login):
        _translate = QtCore.QCoreApplication.translate
        login.setWindowTitle(_translate("login", "Dialog"))
        self.pushButton.setText(_translate("login", "PushButton"))
