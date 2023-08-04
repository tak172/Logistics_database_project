<p align="center">
      <img src="https://i.ibb.co/GdrTzPk/Untitled-logo-2-free-file.jpg" alt="Standart" width="200">
</p>

<p align="center">
   <img src="https://img.shields.io/badge/Qt-v6.4.3-khaki?logo=Qt" alt="Standart">
   <img src="https://img.shields.io/badge/Logistics_database_ptoject-v1.0-khaki" alt="Version">
   <img src="https://img.shields.io/badge/GNU%20General-Public%20License-khaki" alt="License">
</p>

## About

Logistics database project - десктопное приложение для вымышленной компании, занимающейся грузоперевозками. Программа поможет пользователю автоматизировать процесс подсчета прибыли от заказов, расчет важных коэфициентов и поможет отследить, какие маршруты наиболее популярны.

## Requirements

**Логистика**

Имеется некоторый начальный капитал. Есть список городов и расстояний между ними (полный граф). Имеется список грузовиков компании (в т.ч. тип груза (жидкий, сыпучий, контейнеровоз…), грузоподъемность, цена грузовика, расходы на простой, расходы на трассе с грузом, расходы на трассе порожняком…). В каждом городе есть гараж компании. Изначально грузовики как-то распределены по городам. Есть список тарифов на грузоперевозки. Единица времени – сутки. Скорость у всех машин одинаковая. Каждый маршрут должен занимать целое количество суток. Если в один и тот же день грузовик привез груз и загрузился новым, то простоя нет.

Требуется: 

- Поддержка покупки/продажи грузовиков.
- Поддержка оформления заказа на перевозку груза.

Отчеты:

- Коэффициент бесполезного пробега по каждому грузовику компании (отношение порожнего пробега к полезному) и средний по всем грузовикам за год;
- Коэфициент простоя по каждому грузовику и в целом (отношение времени простоя ко времени в пути);
- Активность городов (по суммарному весу отправленного и/или принятого груза);
- Популярные грузы (по суммарному весу груза);
- Финансовый отчет компании (квартал/год).

## Start

Для начала вам необходимо установить Qt (Версия на которой я писал проект указана над разделом **"About"**). Скачать программу можно с официального сайта [Qt](https://www.qt.io/). Если вы находитесь на территории РФ, начните установку с включенным VPN (подойдет любой, желательно без лимита трафика).

Затем установите MySQL. Документация и инструкция по установке находятся [здесь](https://www.mysql.com/downloads/).

Далее нужно собрать драйвер QMYSQL. Инструкцию по сборке и готовые драйвера можно найти в этом [репозитории](https://github.com/thecodemonkey86/qt_mysql_driver).

Последний шаг перед сборкой программы - создать базу данных. Схема базы:

<p align="center"><img src="https://i.ibb.co/xztvwQs/image.png" width="600">
</p>

Не забудьте запустить сервер MySQL (пропишите mysqld в терминал). Поменяйте данные для подключения к бд на свои (mainwindow.cpp), соберите проект и пользуйтесь.

## Instruction

- В появившемся окне при запуске вводим начальный капитал компании.
- **"TRUCK PURCHASE"** - приобрести грузовик.
- **"TRUCK SALE"** - продать грузовик.
- **"ORDER PLACEMENT"** - оформление заказа.
- **"REPORTS"** - отчеты по работе.

## Demonstration

Видео демонстрации работы:

https://github.com/tak172/Logistics_database_project/assets/120005445/37071aa0-8ad6-43d9-9414-a12967fae6f4

## Documentation

- [MySQL](https://dev.mysql.com/);
- [Qt](https://www.qt.io/);

## Developers

- [Kromachev Timofey](https://github.com/tak172)
- [Kromachev Maxim]()

## License
Project Crossword_Generator_bot is distributed under the **GNU General Public License**.
