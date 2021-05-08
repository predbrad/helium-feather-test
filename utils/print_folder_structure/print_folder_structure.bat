@echo off
Set cmd_folder=%CD%
CD ..
CD ..
tree /a >%cmd_folder%\tree.txt
@echo ```>%cmd_folder%\folder_structure.md
more +3 %cmd_folder%\tree.txt>>%cmd_folder%\folder_structure.md
@echo ```>>%cmd_folder%\folder_structure.md
exit