# URIJudge
:coffee: Soluções em linguagem C dos problemas URI Online Judge

## Summary

- [Requirements](#requirements)
    - [Installation Guide](#installation)
- [Getting Started](#orientations)
- [Generating executable](#executable)
- [Project Tests](#tests)

## <span id='requirements'>Requirements</span>

- For the project to be successfully built, it will be necessary to
  installation of the following programs:
    - __make__ to automate project compilation,
      generate documentation and compile tests
    - __valgrind__ to generate statistics during compilation
      of memory usage and processing
    - __doxygen__ to generate project documentation through
      comments encoded in the code files
    - __cpputest__ for project testing coding
- If you encounter errors when using _doxygen_ for the _graphviz_ tool
  because it was not found, run:
  ``` sh
  $ sudo apt-get install graphviz
  ```

### <span id='installation'>Installation Guide</span>

- The installation process is relatively simple
    - For those who use some Debian-derived distribution, such as
      Ubuntu and Elementary, just run the commands:
      ``` sh
      $ sudo apt-get update
      $ sudo apt-get install build-essential
      $ sudo apt-get install valgrind
      $ sudo apt-get install doxygen
      $ sudo apt-get install graphviz
      $ sudo apt-get install cpputest
      ```
    - For Fedora, you will have to execute the commands:
      ``` sh
      $ yum install make automake gcc gcc-c++ kernel-devel
      $ yum install valgrind
      $ dnf copr enable rspanton/cpputest
      $ dnf install cpputest
      ```
      - For _doxygen_ installation I recommend the
       installation provided at [official site](http://www.doxygen.nl/manual/install.html)

## <span id='orientations'>Getting Started</span>

- Each exercise has its own documentation
- Currently the project has the following list of supported languages
- The build command has the option of specifying a language
  for extracting documentation through the __LANGUAGE__ argument
- Below is the list of languages ​​currently supported:
    - `_PT_BR`: Portuguese
    - `_EN_US`: English

## <span id='executable'>Generating the executable</span>

- Access the _build_ directory of the chosen exercise
- Run the command below with the option to specify or not
  a language for documentation extraction
  ``` sh
  $ make build.program [LANGUAGE=<language>]
  ```
- Examples:
  ``` sh
  $ make build.program
  $ make build.program LANGUAGE=_EN_BR
  ```
- If you do not want the process of generating the documentation to stop,
  requesting the absolute path of the files of an exercise
  (located in src/), follow the instructions below:
    - Add the variable PROJECT_DIR to the ~/.bashrc file with the
      full src/ exercise directory path
      ``` sh
      export PROJECT_DIR=<src_path>
      ```

## <span id='tests'>Project Tests</span>

- To generate the tests run after generating the executable
  (previous step), inside the _build_ directory:
  ``` sh
  $ make build.tests
  $ ../bin/tests
  ```
