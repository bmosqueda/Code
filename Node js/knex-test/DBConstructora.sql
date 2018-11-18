CREATE TABLE Trabajadores(
  id SERIAL PRIMARY KEY, 
  nombre TEXT NOT NULL, 
  tarifa_hora DECIMAL NOT NULL,
  tipo_oficio TEXT NOT NULL,
  supervisor_id INT REFERENCES Trabajadores
);

CREATE TABLE Edificios(
  id SERIAL PRIMARY KEY, 
  direccion TEXT NOT NULL, 
  tipo TEXT NOT NULL,
  nivel_calidad INT NOT NULL,
  categoria INT NOT NULL
);

CREATE TABLE Asignaciones(
  trabajador_id INT NOT NULL REFERENCES Trabajadores, 
  edificio_id INT NOT NULL REFERENCES Edificios, 
  fecha_inicio DATE DEFAULT CURRENT_DATE,
  numero_dias INT NOT NULL,
  PRIMARY KEY(trabajador_id, edificio_id, fecha_inicio)
);