# mishanya-bot-project

Проект по разработке/оживлению человекоподного робота Мишаня -> [Описание робота](docs/equipment/equipment.md)

- [Подготовка окружения](#подготовка-окружения)
  - [Установка форматера глабально](#установка-форматера-глабально)
  - [Установка инструментов линта через локальное окружение (poetry)](#установка-инструментов-линта-через-локальное-окружение-poetry)
- [Пара моментов по разработке](#пара-моментов-по-разработке)
- [Заметки по работе в-целом](#заметки-по-работе-в-целом)
- [Глобальные цели](#глобальные-цели)
- [Ресурсы](#ресурсы)

## Подготовка окружения

### Установка форматера глабально

Устанавливаем `clang-format`
   - Windows

      Используйте установочный файл с [официального сайта LLVM](https://llvm.org/builds/) 

   - Linux

      ```bash
      sudo apt install clang-format
      ```

### Установка инструментов линта через локальное окружение (poetry)

1. Устанавливаем make
    - Windows:
  
      Устанавливаем [chocolatey](https://chocolatey.org/install) и устанавливаем `make` с помощью команды:

      ```bash
      choco install make 
      ```

    - Linux:

      ```bash
      sudo apt-get install build-essential
      ```

1. Устанавливаем `python 3.8`

   - Windows

      Устанавливаем через [официальный установщик](https://www.python.org/downloads/)

   - Linux

      ```bash
      sudo apt install python3.8-dev
      ```

1. Устанавливаем [poetry](https://python-poetry.org/docs/#installing-with-the-official-installer)

    - Windows

      Используйте [официальные инструкции](https://python-poetry.org/docs/#installing-with-the-official-installer) или команду `powershell`

      ```bash
      (Invoke-WebRequest -Uri https://install.python-poetry.org -UseBasicParsing).Content | py -
      ```

    - Linux

      ```bash
      make poetry-install
      ```

1. Устанавливаем требуемые пакеты и инструменты с помощью команды

    ```bash
    make env-init
    ```

## Пара моментов по разработке

- Основная разработка ведется через ветку `develop`
- Flow работы над задачей
  - Для нее обязательно должна быть создана задача в issues, например `#8 Разработка кода для модуля локтя руки`
  - Во вкладке Projects переводите ее в `In progress` колонку
  - Создаете ветку с названием `8_hand_module_code_creation`
  - Работаете в этой ветке (комитить желательно делать по завершении какой-то части задачи и всегда в конце дня)
  - После завершения работы создаете Pull Request, в котором описываете, что сделано и назначаете ревьюверов (всех остальных в проекте)
  - Как только ревью пройдено и получено подтверждение - ветку сливает администратор (Леша)
- Канбан доска для проекта - вкладка Projects
- Файлы больше 100 KB храним в [Git LFS](https://git-lfs.github.com/)
- Для каждой разработанной подсистемы требуется написать маленький тест, который будет запускать простую программу, использующую разработанные функции и демонстрировать работоспособность

## Заметки по работе в-целом

- Не стесняемся задавать вопросы по *любой* теме насчет проекта - лучше, чтобы все понимали, в каком состоянии что сейчас находится, чем что-то скрывать
- Чат не для хранения - его может заваливать переписками и общением!
- Документы, полезные ссылки или другая полезная инфа - обязательно в `.md` файлы в репозитории хранить!
- Если файлом надо поделиться - кладем в репо и отсюда кидаем ссылку в чат (так гарантируется, что ничего не потеряется) 

## Глобальные цели

- Stage 1 - Восстановление базового функционала
  - Стараемся добиться того, чтобы все части робота работали и все могло управляться через единый МК
- Stage 2 - Добавляется интеграция с ROS и организуется математическая модель кинематики с имплементацией в роботе
- Stage 3 - Разработка SDK для робота (прослойка для верхнеуровневого управления)
- Stage 4 - Разработка сценариев для автономного движения и выполнения задач (демо продукта, сбор информации с людей, и т.д.)

## Ресурсы

- [Хранилище больших файлов](https://disk.yandex.ru/d/VdiUvhrjdGQnWQ) (за доступом обращайтесь к [@KaiL4eK](https://github.com/KaiL4eK))
