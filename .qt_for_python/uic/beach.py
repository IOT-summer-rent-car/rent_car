# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/beach.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_beach(object):
    def setupUi(self, beach):
        beach.setObjectName("beach")
        beach.resize(1058, 731)
        self.label = QtWidgets.QLabel(beach)
        self.label.setGeometry(QtCore.QRect(190, 30, 661, 17))
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(beach)
        self.lineEdit.setGeometry(QtCore.QRect(190, 50, 671, 25))
        self.lineEdit.setObjectName("lineEdit")
        self.pushButton = QtWidgets.QPushButton(beach)
        self.pushButton.setGeometry(QtCore.QRect(860, 50, 51, 25))
        self.pushButton.setObjectName("pushButton")
        self.comboBox = QtWidgets.QComboBox(beach)
        self.comboBox.setGeometry(QtCore.QRect(100, 50, 86, 25))
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.tableWidget = QtWidgets.QTableWidget(beach)
        self.tableWidget.setGeometry(QtCore.QRect(180, 120, 701, 501))
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(3)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(2, item)
        self.exit = QtWidgets.QPushButton(beach)
        self.exit.setGeometry(QtCore.QRect(480, 660, 89, 25))
        self.exit.setObjectName("exit")
        self.label_2 = QtWidgets.QLabel(beach)
        self.label_2.setGeometry(QtCore.QRect(420, 630, 51, 17))
        self.label_2.setText("")
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(beach)
        self.label_3.setGeometry(QtCore.QRect(480, 630, 151, 17))
        self.label_3.setObjectName("label_3")

        self.retranslateUi(beach)
        QtCore.QMetaObject.connectSlotsByName(beach)

    def retranslateUi(self, beach):
        _translate = QtCore.QCoreApplication.translate
        beach.setWindowTitle(_translate("beach", "Dialog"))
        self.label.setText(_translate("beach", "어디로 여행을 떠나시겠습니까?"))
        self.pushButton.setText(_translate("beach", "검색"))
        self.comboBox.setItemText(0, _translate("beach", "선택"))
        self.comboBox.setItemText(1, _translate("beach", "지역명"))
        self.comboBox.setItemText(2, _translate("beach", "도시명"))
        self.comboBox.setItemText(3, _translate("beach", "해변명"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("beach", "지역명"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("beach", "도시명"))
        item = self.tableWidget.horizontalHeaderItem(2)
        item.setText(_translate("beach", "해변명"))
        self.exit.setText(_translate("beach", "돌아가기"))
        self.label_3.setText(_translate("beach", "해변을 선택하였습니다."))
