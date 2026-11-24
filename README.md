# Homework01 — Unreal Engine

## Домашнее задание №1. Расширение Third Person Template

**Версия Unreal Engine:** 5.8.4

### Реализованные механики

- Создан C++ класс ABaseCharacter, наследуемый от ACharacter.
- BP_ThirdPersonCharacter наследуется от ABaseCharacter.
- Настроены дополнительные действия Enhanced Input: IA_Sprint и IA_Interact.
- Обработка новых действий реализована на C++ через BindAction в SetupPlayerInputComponent.
- Реализована механика спринта с увеличением MaxWalkSpeed до 900 см/с.
- При отпускании клавиши спринта восстанавливается стандартная скорость персонажа.
- Состояние спринта хранится в переменной bIsSprinting с модификатором BlueprintReadOnly.
- Создан Dynamic Multicast Delegate OnInteraction.
- При взаимодействии вызывается делегат, на который подписан BP_ThirdPersonCharacter.
- При нажатии клавиши E выводится сообщение Interaction triggered!
- Сохранены стандартные механики передвижения, прыжка и управления камерой.

### Управление

| Клавиша | Действие |
|---|---|
| W, A, S, D | Передвижение |
| Мышь | Управление камерой |
| Space | Прыжок |
| Left Shift | Спринт |
| E | Взаимодействие |

### Архитектура проекта

- ABaseCharacter — основная логика спринта и взаимодействия на C++.
- BP_ThirdPersonCharacter — Blueprint игрового персонажа.
- IMC_Default — контекст назначения клавиш Enhanced Input.
- IA_Sprint — действие спринта.
- IA_Interact — действие взаимодействия.
- ABP_Unarmed — стандартный Animation Blueprint персонажа.

### Статус выполнения

Основные механики управления, спринта и взаимодействия реализованы и проверены.

Отдельное состояние Sprint в Animation Blueprint и дополнительная механика Stamina не реализованы.
