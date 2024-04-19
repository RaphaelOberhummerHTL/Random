# Random

## Parameterabfrage

Dieses C-Programm dient zur Verarbeitung von Befehlszeilenparametern und führt entsprechende Aktionen aus. Es enthält folgende Funktionen:

- Parameterabfrage: Diese Funktion überprüft die übergebenen Parameter und führt entsprechende Aktionen aus. Wenn ungültige Parameter übergeben werden, gibt sie Fehlermeldungen aus. Ansonsten führt sie die entsprechenden Aktionen basierend auf den Parametern aus.

- Kein_Internet: Diese Funktion gibt eine zufällige Meldung aus, wenn keine Internetverbindung besteht.

- Zu_viele_Parameter: Diese Funktion gibt eine zufällige Meldung aus, wenn zu viele Parameter übergeben wurden.

- keineHilfe: Diese Funktion gibt eine Meldung aus, falls der Parameter "--keineHilfe" übergeben wird.

- Hilfe: Diese Funktion gibt eine Liste der verfügbaren Parameter aus, falls der Parameter "--Hilfe" übergeben wird.

- keine_Parameter: Diese Funktion führt je nach Zufallsauswahl eine von drei verschiedenen Aktionen aus, wenn keine Parameter übergeben wurden.

Um das Programm auszuführen, können unter Linux folgende Befehle:
```
./Random
./Random --Hilfe
./Random --Installieren
./Random --Deinstallieren
./Random --keineHilfe
```
und für Windows folgende Befehle
```
.\Random
.\Random --Hilfe
.\Random --Installieren
.\Random --Deinstallieren
.\Random --keineHilfe
```
verwendet werden. Dieser muss jedoch bis jetzt noch im gleichen Ordner ausgeführt werden wo die Ausführbare Datei liegt.

Für das Standardverhalten genügt es, das Programm ohne Parameter auszuführen.

Fühlen Sie sich frei, den Eintrag entsprechend anzupassen oder zu erweitern!