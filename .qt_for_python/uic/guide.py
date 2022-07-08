# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/guide.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Guide(object):
    def setupUi(self, Guide):
        Guide.setObjectName("Guide")
        Guide.resize(701, 675)
        self.tableWidget = QtWidgets.QTableWidget(Guide)
        self.tableWidget.setGeometry(QtCore.QRect(110, 120, 451, 441))
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(2)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        self.label = QtWidgets.QLabel(Guide)
        self.label.setGeometry(QtCore.QRect(90, 40, 661, 17))
        self.label.setObjectName("label")
        self.pushButton = QtWidgets.QPushButton(Guide)
        self.pushButton.setGeometry(QtCore.QRect(540, 60, 51, 25))
        self.pushButton.setObjectName("pushButton")
        self.exit = QtWidgets.QPushButton(Guide)
        self.exit.setGeometry(QtCore.QRect(290, 610, 89, 25))
        self.exit.setObjectName("exit")
        self.lineEdit = QtWidgets.QLineEdit(Guide)
        self.lineEdit.setGeometry(QtCore.QRect(90, 60, 451, 25))
        self.lineEdit.setObjectName("lineEdit")
        self.label_2 = QtWidgets.QLabel(Guide)
        self.label_2.setGeometry(QtCore.QRect(200, 580, 91, 20))
        self.label_2.setText("")
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(Guide)
        self.label_3.setGeometry(QtCore.QRect(300, 580, 171, 17))
        self.label_3.setObjectName("label_3")

        self.retranslateUi(Guide)
        QtCore.QMetaObject.connectSlotsByName(Guide)

    def retranslateUi(self, Guide):
        _translate = QtCore.QCoreApplication.translate
        Guide.setWindowTitle(_translate("Guide", "Dialog"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("Guide", "가이드"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("Guide", "가능상태"))
        self.label.setText(_translate("Guide", "가이드 현황"))
        self.pushButton.setText(_translate("Guide", "검색"))
        self.exit.setText(_translate("Guide", "돌아가기"))
        self.label_3.setText(_translate("Guide", "가이드를 선택하였습니다."))
