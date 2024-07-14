#pragma once

enum Genero {
	Femenino = 0,
	Masculino,
	Otro
};

struct Votante {
	Genero genero;
	int edad;
};

