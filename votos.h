#pragma once

enum Genero {
	Femenino = 0,
	Masculino,
	Otro
};

struct Votante {
	Lista voto;
	int genero;
	int edad;
};