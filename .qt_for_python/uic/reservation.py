# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/iot/코드/untitled/reservation.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_reservation(object):
    def setupUi(self, reservation):
        reservation.setObjectName("reservation")
        reservation.resize(698, 436)
        self.calendarWidget = QtWidgets.QCalendarWidget(reservation)
        self.calendarWidget.setGeometry(QtCore.QRect(110, 100, 471, 271))
        self.calendarWidget.setObjectName("calendarWidget")
        self.label = QtWidgets.QLabel(reservation)
        self.label.setGeometry(QtCore.QRect(290, 20, 101, 51))
        font = QtGui.QFont()
        font.setFamily("Ubuntu Mono")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")

        self.retranslateUi(reservation)
        QtCore.QMetaObject.connectSlotsByName(reservation)

    def retranslateUi(self, reservation):
        _translate = QtCore.QCoreApplication.translate
        reservation.setWindowTitle(_translate("reservation", "Dialog"))
        self.label.setText(_translate("reservation", "예약하기"))
