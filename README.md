<h1 align="center">
	42cursus' Get_next_line
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' Get_next_line project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/achrafelkhnissi/1337/blob/master/42curses/README.md"><b>42cursus repo</b></a>.
</p>


<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
</h3>


## 🗣️ About
The goal of this project is to learn about static variables and improving your memory management skills (allocating and freeing).

```c
	GET_NEXT_LINE
	-------------
	DESCRIPTION
	This function takes an opened file descriptor and returns its next line.
	This function has undefined behavior when reading from a binary file.
	PARAMETERS
	#1. A file descriptor
	RETURN VALUES
	If successful, get_next_line returns a string with the full line ending in
	a line break (`\n`) when there is one.
	If an error occurs, or there's nothing more to read, it returns NULL.
	----------------------------------------------------------------------------
	AUXILIARY FUNCTIONS
	-------------------
	READ_TO_LEFT_STR
	-----------------
	DESCRIPTION
	Takes the opened file descriptor and saves on a "buff" variable what readed
	from it. Then joins it to the cumulative static variable for the persistence
	of the information.
	PARAMETERS
	#1. A file descriptor.
	#2. The pointer to the cumulative static variable from previous runs of
	get_next_line.
	RETURN VALUES
	The new static variable value with buffer joined for the persistence of the info,
	or NULL if error.

```

## 📌 Useful Links

* [ge_next_line **Requirements**](https://leeters.netlify.app/get-next-line/)
## :computer: Technologies

* [C](https://devdocs.io/)
* [Makefile](https://www.gnu.org/software/make/manual/make.html)
* [Shell](https://unixguide.readthedocs.io/en/latest/unixcheatsheet/)
* [gcc](https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/)

 ## Autor

Made by Hicham Amaarour👋 [See my linkedin](https://www.linkedin.com/in/hicham-amaarour-5a1b84220/)

