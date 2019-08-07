# Exercise 1001

> Beginner Category

- [Requirements](#requirements)
- [Generating executable and documentation](#executable)

## <span id='requirements'>Requirements</span>

- For the project to be successfully built, it will be necessary to
  installation of the following programs:
    - make
    - valgrind
    - doxygen
    - graphviz
    - cpputest

## <span id='executable'>Generating executable and documentation</span>

- Add the variable PROJECT_DIR to your .bashrc file with the
  full path to the project directory (src/) allowing
  the reading and construction of documentation
    ``` sh
    export PROJECT_DIR=<rc_path>
    ```
- Access the _build_ directory
- Run the command below passing the language in which the documentation will be exported
    ``` sh
    $ make build.program LANGUAGE=<language>
    ```
- List of languages ​​currently supported in the project
    - `_PT_BR`: Portuguese
    - `_EN_US`: English
