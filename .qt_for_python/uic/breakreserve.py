# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/breakreserve.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_breakreserve(object):
    def setupUi(self, breakreserve):
        breakreserve.setObjectName("breakreserve")
        breakreserve.resize(667, 654)
        self.tableWidget = QtWidgets.QTableWidget(breakreserve)
        self.tableWidget.setGeometry(QtCore.QRect(100, 80, 451, 441))
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(4)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(3, item)
        self.label = QtWidgets.QLabel(breakreserve)
        self.label.setGeometry(QtCore.QRect(110, 50, 301, 20))
        self.label.setObjectName("label")
        self.exit = QtWidgets.QPushButton(breakreserve)
        self.exit.setGeometry(QtCore.QRect(280, 570, 89, 25))
        self.exit.setObjectName("exit")
        self.breakbt = QtWidgets.QPushButton(breakreserve)
        self.breakbt.setGeometry(QtCore.QRect(280, 530, 89, 25))
        self.breakbt.setObjectName("breakbt")

        self.retranslateUi(breakreserve)
        QtCore.QMetaObject.connectSlotsByName(breakreserve)

    def retranslateUi(self, breakreserve):
        _translate = QtCore.QCoreApplication.translate
        breakreserve.setWindowTitle(_translate("breakreserve", "Dialog"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("breakreserve", "해변명"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("breakreserve", "숙소명"))
        item = self.tableWidget.horizontalHeaderItem(2)
        item.setText(_translate("breakreserve", "가이드명"))
        item = self.tableWidget.horizontalHeaderItem(3)
        item.setText(_translate("breakreserve", "날짜"))
        self.label.setText(_translate("breakreserve", "예약 현황"))
        self.exit.setText(_translate("breakreserve", "돌아가기"))
        self.breakbt.setText(_translate("breakreserve", "예약취소"))
