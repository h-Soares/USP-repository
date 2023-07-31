-- -----------------------------------------------------
-- Table CEP
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS CEP (
  CEP INTEGER NOT NULL,
  estado VARCHAR(45) NOT NULL,
  cidade VARCHAR(45) NOT NULL,
  bairro VARCHAR(45) NOT NULL,
  PRIMARY KEY (CEP))
;


-- -----------------------------------------------------
-- Table Usuario
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Usuario (
idUsuario INTEGER NOT NULL,
Nome VARCHAR(45) NOT NULL,
Senha VARCHAR(45) NOT NULL,
Sexo VARCHAR(45) NOT NULL,
Anos_trabalhados INTEGER NOT NULL,
Ag INTEGER NOT NULL,
CC INTEGER NOT NULL,
Nacionalidade VARCHAR(45) NOT NULL,
tipo_usuario VARCHAR(45) NOT NULL,
Nro INTEGER NOT NULL,
Rua VARCHAR(45) NOT NULL,
Email VARCHAR(45) NOT NULL,
Celular VARCHAR(45) NOT NULL,
CEP INTEGER NOT NULL,
PRIMARY KEY (idUsuario),
CONSTRAINT fk_Usuario_CEP1
FOREIGN KEY (CEP)
REFERENCES CEP (CEP)

)
;
-- -----------------------------------------------------
-- Table Diretor_Adm_formacao
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Diretor_Adm_formacao (
Usuario_idDiretor_adm INTEGER NOT NULL,
Cont INTEGER NOT NULL,
Formacao VARCHAR(45) NULL,
PRIMARY KEY (Usuario_idDiretor_adm, Cont),
CONSTRAINT fk_Usuario_idDiretor_adm
FOREIGN KEY (Usuario_idDiretor_adm)
REFERENCES Usuario (idUsuario)
)
;


-- -----------------------------------------------------
-- Table Bailarino
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Bailarino (
Usuario_idUsuario INTEGER NOT NULL,
Salario INTEGER NOT NULL,
PRIMARY KEY (Usuario_idUsuario),
CONSTRAINT fk_Bailarino_Usuario
FOREIGN KEY (Usuario_idUsuario)
REFERENCES Usuario (idUsuario)

)
;


-- -----------------------------------------------------
-- Table Professor
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Professor (
Usuario_idProfessor INTEGER NOT NULL,
Salario INTEGER NOT NULL,
PRIMARY KEY (Usuario_idProfessor),
CONSTRAINT fk_Professor_Usuario1
FOREIGN KEY (Usuario_idProfessor)
REFERENCES Usuario (idUsuario)

)
;

CREATE INDEX fk_Professor_Usuario1_idx ON Professor (Usuario_idProfessor ASC) ;


-- -----------------------------------------------------
-- Table Diretor_Art_formacao
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Diretor_Art_formacao (
Usuario_idDiretor_art INTEGER NOT NULL,
Cont INTEGER NOT NULL,
Formacao VARCHAR(45) NULL,
PRIMARY KEY (Usuario_idDiretor_art, Cont),
CONSTRAINT fk_Diretor_Art_Usuario1
FOREIGN KEY (Usuario_idDiretor_art)
REFERENCES Usuario (idUsuario)

)
;

CREATE INDEX fk_Diretor_Art_Usuario1_idx ON Diretor_Art_formacao (Usuario_idDiretor_art ASC) ;


-- -----------------------------------------------------
-- Table Bailarino_especializacao
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Bailarino_especializacao (
Bailarino_Usuario_idUsuario INTEGER NOT NULL,
Cont INTEGER NOT NULL,
Especializacao VARCHAR(45) NULL,
PRIMARY KEY (Bailarino_Usuario_idUsuario, Cont),
CONSTRAINT fk_Bailarino_especializacao_Bailarino1
FOREIGN KEY (Bailarino_Usuario_idUsuario)
REFERENCES Bailarino (Usuario_idUsuario)

)
;

CREATE INDEX fk_Bailarino_especializacao_Bailarino1_idx ON Bailarino_especializacao (Bailarino_Usuario_idUsuario ASC)  ;


-- -----------------------------------------------------
-- Table Professor_especializacao
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Professor_especializacao (
Professor_Usuario_idProfessor INTEGER NOT NULL,
Cont INTEGER NOT NULL,
Especializacao VARCHAR(45) NULL,
PRIMARY KEY (Professor_Usuario_idProfessor, Cont),
CONSTRAINT fk_Professor_especializacao_Professor1
FOREIGN KEY (Professor_Usuario_idProfessor)
REFERENCES Professor (Usuario_idProfessor)

)
;

CREATE INDEX fk_Professor_especializacao_Professor1_idx ON Professor_especializacao (Professor_Usuario_idProfessor ASC) ;


-- -----------------------------------------------------
-- Table Aviso
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Aviso (
idAviso INTEGER NOT NULL,
Professor_Usuario_idProfessor INTEGER NOT NULL,
Diretor_Adm_Usuario_idDiretor_adm INTEGER NOT NULL,
Cont INTEGER NOT NULL,
data_publicacao DATE NOT NULL,
titulo VARCHAR(45) NOT NULL,
descricao TEXT NOT NULL,
PRIMARY KEY (idAviso),
CONSTRAINT fk_Aviso_Professor1
FOREIGN KEY (Professor_Usuario_idProfessor)
REFERENCES Professor (Usuario_idProfessor)

,
CONSTRAINT fk_Aviso_Diretor_Adm1
FOREIGN KEY (Diretor_Adm_Usuario_idDiretor_adm, Cont)
REFERENCES Diretor_Adm_formacao (Usuario_idDiretor_adm, Cont)

)
;

CREATE INDEX fk_Aviso_Professor1_idx ON Aviso (Professor_Usuario_idProfessor ASC) ;

CREATE INDEX fk_Aviso_Diretor_Adm1_idx ON Aviso (Diretor_Adm_Usuario_idDiretor_adm ASC) ;


-- -----------------------------------------------------
-- Table Patrocinador
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Patrocinador (
nome VARCHAR(45) NOT NULL,
Diretor_Adm_Usuario_idDiretor_adm INTEGER NOT NULL,
Cont INTEGER NOT NULL,
sede VARCHAR(45) NOT NULL,
duracao_contrato INTEGER NOT NULL,
valor INTEGER NOT NULL,
PRIMARY KEY (nome),
CONSTRAINT fk_Patrocinador_Diretor_Adm1
FOREIGN KEY (Diretor_Adm_Usuario_idDiretor_adm, Cont)
REFERENCES Diretor_Adm_formacao (Usuario_idDiretor_adm, Cont)

)
;

CREATE INDEX fk_Patrocinador_Diretor_Adm1_idx ON Patrocinador (Diretor_Adm_Usuario_idDiretor_adm ASC) ;


-- -----------------------------------------------------
-- Table Movimentacao_Financeira
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Movimentacao_Financeira (
codigo INTEGER NOT NULL,
Diretor_Adm_Usuario_idDiretor_adm INTEGER NOT NULL,
Cont INTEGER NOT NULL,
data DATE NOT NULL,
tipo VARCHAR(45) NOT NULL,
valor INTEGER NOT NULL,
PRIMARY KEY (codigo),
CONSTRAINT fk_Movimentacao_Financeira_Diretor_Adm1
FOREIGN KEY (Diretor_Adm_Usuario_idDiretor_adm, Cont)
REFERENCES Diretor_Adm_formacao (Usuario_idDiretor_adm, Cont)

)
;

CREATE INDEX fk_Movimentacao_Financeira_Diretor_Adm1_idx ON Movimentacao_Financeira (Diretor_Adm_Usuario_idDiretor_adm ASC) ;


-- -----------------------------------------------------
-- Table Relatorio
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Relatorio (
codigo INTEGER NOT NULL,
Professor_Usuario_idProfessor INTEGER NOT NULL,
Diretor_Art_Usuario_idDiretor_art INTEGER NOT NULL,
Cont INTEGER NOT NULL,
titulo VARCHAR(45) NOT NULL,
PRIMARY KEY (codigo),
CONSTRAINT fk_Relatorio_Professor1
FOREIGN KEY (Professor_Usuario_idProfessor)
REFERENCES Professor (Usuario_idProfessor)

,
CONSTRAINT fk_Relatorio_Diretor_Art1
FOREIGN KEY (Diretor_Art_Usuario_idDiretor_art, Cont)
REFERENCES Diretor_Art_formacao (Usuario_idDiretor_art, Cont)

)
;

CREATE INDEX fk_Relatorio_Professor1_idx ON Relatorio (Professor_Usuario_idProfessor ASC) ;

CREATE INDEX fk_Relatorio_Diretor_Art1_idx ON Relatorio (Diretor_Art_Usuario_idDiretor_art ASC) ;


-- -----------------------------------------------------
-- Table DiretorArt_Aviso
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS DiretorArt_Aviso (
Aviso_idAviso INTEGER NOT NULL,
Diretor_Art_Usuario_idDiretor_art INTEGER NOT NULL,
Cont INTEGER NOT NULL,
PRIMARY KEY (Aviso_idAviso, Diretor_Art_Usuario_idDiretor_art, Cont),
CONSTRAINT fk_Diretor_Art_has_Aviso_Diretor_Art1
FOREIGN KEY (Diretor_Art_Usuario_idDiretor_art, Cont)
REFERENCES Diretor_Art_formacao (Usuario_idDiretor_art, Cont)

,
CONSTRAINT fk_Diretor_Art_has_Aviso_Aviso1
FOREIGN KEY (Aviso_idAviso)
REFERENCES Aviso (idAviso)

)
;

CREATE INDEX fk_Diretor_Art_has_Aviso_Aviso1_idx ON DiretorArt_Aviso (Aviso_idAviso ASC)  ;

CREATE INDEX fk_Diretor_Art_has_Aviso_Diretor_Art1_idx ON DiretorArt_Aviso (Diretor_Art_Usuario_idDiretor_art ASC) ;


-- -----------------------------------------------------
-- Table Espetaculo
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Espetaculo (
idEspetaculo INTEGER NOT NULL,
Diretor_Adm_Usuario_idDiretor_adm INTEGER NOT NULL,
Cont_DiretorAdm INTEGER NOT NULL,
Diretor_Art_Usuario_idDiretor_art INTEGER NOT NULL,
Cont_DiretorArt INTEGER NOT NULL,
nome VARCHAR(45) NOT NULL,
data DATE NOT NULL,
duracao INTEGER NOT NULL,
horario VARCHAR(45) NOT NULL,
PRIMARY KEY (idEspetaculo),
CONSTRAINT fk_Espetaculo_Diretor_Adm1
FOREIGN KEY (Diretor_Adm_Usuario_idDiretor_adm, Cont_DiretorAdm)
REFERENCES Diretor_Adm_formacao (Usuario_idDiretor_adm, Cont)

,
CONSTRAINT fk_Espetaculo_Diretor_Art1
FOREIGN KEY (Diretor_Art_Usuario_idDiretor_art, Cont_DiretorArt)
REFERENCES Diretor_Art_formacao (Usuario_idDiretor_art, Cont)

)
;

CREATE INDEX fk_Espetaculo_Diretor_Adm1_idx ON Espetaculo (Diretor_Adm_Usuario_idDiretor_adm ASC) ;

CREATE INDEX fk_Espetaculo_Diretor_Art1_idx ON Espetaculo (Diretor_Art_Usuario_idDiretor_art ASC) ;


-- -----------------------------------------------------
-- Table Coreografia
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Coreografia (
idCoreografia INTEGER NOT NULL,
Professor_Usuario_idProfessor INTEGER NOT NULL,
Espetaculo_idEspetaculo INTEGER NOT NULL,
autor VARCHAR(45) NOT NULL,
duracao INTEGER NOT NULL,
PRIMARY KEY (idCoreografia),
CONSTRAINT fk_Coreografia_Professor1
FOREIGN KEY (Professor_Usuario_idProfessor)
REFERENCES Professor (Usuario_idProfessor)

,
CONSTRAINT fk_Coreografia_Espetaculo1
FOREIGN KEY (Espetaculo_idEspetaculo)
REFERENCES Espetaculo (idEspetaculo)

)
;

CREATE INDEX fk_Coreografia_Professor1_idx ON Coreografia (Professor_Usuario_idProfessor ASC) ;

CREATE INDEX fk_Coreografia_Espetaculo1_idx ON Coreografia (Espetaculo_idEspetaculo ASC) ;


-- -----------------------------------------------------
-- Table Figurino
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Figurino (
  idFigurino INTEGER NOT NULL,
  Coreografia_idCoreografia INTEGER NOT NULL,
  quantidade INTEGER NOT NULL,
  PRIMARY KEY (idFigurino),
  CONSTRAINT fk_Figurino_Coreografia1
    FOREIGN KEY (Coreografia_idCoreografia)
    REFERENCES Coreografia (idCoreografia)

)
;

CREATE INDEX fk_Figurino_Coreografia1_idx ON Figurino (Coreografia_idCoreografia ASC)  ;


-- -----------------------------------------------------
-- Table Musica
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Musica (
id_musica VARCHAR(45) NOT NULL,
nome VARCHAR(45) NOT NULL,
autor VARCHAR(45) NOT NULL,
duracao INTEGER NOT NULL,
PRIMARY KEY (id_musica))
;


-- -----------------------------------------------------
-- Table Figurino_Tamanho
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Figurino_Tamanho (
  Figurino_idFigurino INTEGER NOT NULL,
  contador INTEGER NOT NULL,
  tamanho INTEGER NOT NULL,
  PRIMARY KEY (Figurino_idFigurino, contador),
  CONSTRAINT fk_Figurino_Tamanho_Figurino1
    FOREIGN KEY (Figurino_idFigurino)
    REFERENCES Figurino (idFigurino)

)
;


-- -----------------------------------------------------
-- Table Ensaio
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Ensaio (
contagem INTEGER NOT NULL,
Espetaculo_idEspetaculo INTEGER NOT NULL,
Professor_Usuario_idProfessor INTEGER NOT NULL,
sala VARCHAR(45) NOT NULL,
data DATE NOT NULL,
horario VARCHAR(45) NOT NULL,
PRIMARY KEY (contagem, Espetaculo_idEspetaculo),
CONSTRAINT fk_Ensaio_Espetaculo1
FOREIGN KEY (Espetaculo_idEspetaculo)
REFERENCES Espetaculo (idEspetaculo)

,
CONSTRAINT fk_Ensaio_Professor1
FOREIGN KEY (Professor_Usuario_idProfessor)
REFERENCES Professor (Usuario_idProfessor)

)
;

CREATE INDEX fk_Ensaio_Espetaculo1_idx ON Ensaio (Espetaculo_idEspetaculo ASC) ;

CREATE INDEX fk_Ensaio_Professor1_idx ON Ensaio (Professor_Usuario_idProfessor ASC) ;


-- -----------------------------------------------------
-- Table Bailarino_Ensaio
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Bailarino_Ensaio (
Bailarino_Usuario_idUsuario INTEGER NOT NULL,
Ensaio_contagem INTEGER NOT NULL,
Ensaio_Espetaculo_idEspetaculo INTEGER NOT NULL,
PRIMARY KEY (Bailarino_Usuario_idUsuario, Ensaio_contagem, Ensaio_Espetaculo_idEspetaculo),
CONSTRAINT fk_Bailarino_has_Ensaio_Bailarino1
FOREIGN KEY (Bailarino_Usuario_idUsuario)
REFERENCES Bailarino (Usuario_idUsuario)

,
CONSTRAINT fk_Bailarino_has_Ensaio_Ensaio1
FOREIGN KEY (Ensaio_contagem , Ensaio_Espetaculo_idEspetaculo)
REFERENCES Ensaio (contagem , Espetaculo_idEspetaculo)

)
;

CREATE INDEX fk_Bailarino_has_Ensaio_Ensaio1_idx ON Bailarino_Ensaio (Ensaio_contagem ASC, Ensaio_Espetaculo_idEspetaculo ASC) ;

CREATE INDEX fk_Bailarino_has_Ensaio_Bailarino1_idx ON Bailarino_Ensaio (Bailarino_Usuario_idUsuario ASC) ;


-- -----------------------------------------------------
-- Table Bailarino_Espetaculo
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Bailarino_Espetaculo (
Bailarino_Usuario_idUsuario INTEGER NOT NULL,
Espetaculo_idEspetaculo INTEGER NOT NULL,
PRIMARY KEY (Bailarino_Usuario_idUsuario, Espetaculo_idEspetaculo),
CONSTRAINT fk_Bailarino_has_Espetaculo_Bailarino1
FOREIGN KEY (Bailarino_Usuario_idUsuario)
REFERENCES Bailarino (Usuario_idUsuario)

,
CONSTRAINT fk_Bailarino_has_Espetaculo_Espetaculo1
FOREIGN KEY (Espetaculo_idEspetaculo)
REFERENCES Espetaculo (idEspetaculo)

)
;

CREATE INDEX fk_Bailarino_has_Espetaculo_Espetaculo1_idx ON Bailarino_Espetaculo (Espetaculo_idEspetaculo ASC) ;

CREATE INDEX fk_Bailarino_has_Espetaculo_Bailarino1_idx ON Bailarino_Espetaculo (Bailarino_Usuario_idUsuario ASC) ;


-- -----------------------------------------------------
-- Table Professor_Espetaculo
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Professor_Espetaculo (
Professor_Usuario_idProfessor INTEGER NOT NULL,
Espetaculo_idEspetaculo INTEGER NOT NULL,
PRIMARY KEY (Professor_Usuario_idProfessor, Espetaculo_idEspetaculo),
CONSTRAINT fk_Professor_has_Espetaculo_Professor1
FOREIGN KEY (Professor_Usuario_idProfessor)
REFERENCES Professor (Usuario_idProfessor)

,
CONSTRAINT fk_Professor_has_Espetaculo_Espetaculo1
FOREIGN KEY (Espetaculo_idEspetaculo)
REFERENCES Espetaculo (idEspetaculo)

)
;

CREATE INDEX fk_Professor_has_Espetaculo_Espetaculo1_idx ON Professor_Espetaculo (Espetaculo_idEspetaculo ASC) ;

CREATE INDEX fk_Professor_has_Espetaculo_Professor1_idx ON Professor_Espetaculo (Professor_Usuario_idProfessor ASC) ;


-- -----------------------------------------------------
-- Table Patrocinador_Espetaculo
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Patrocinador_Espetaculo (
Patrocinador_nome VARCHAR(45) NOT NULL,
Espetaculo_idEspetaculo INTEGER NOT NULL,
PRIMARY KEY (Patrocinador_nome, Espetaculo_idEspetaculo),
CONSTRAINT fk_Patrocinador_has_Espetaculo_Patrocinador1
FOREIGN KEY (Patrocinador_nome)
REFERENCES Patrocinador (nome)

,
CONSTRAINT fk_Patrocinador_has_Espetaculo_Espetaculo1
FOREIGN KEY (Espetaculo_idEspetaculo)
REFERENCES Espetaculo (idEspetaculo)

)
;

CREATE INDEX fk_Patrocinador_has_Espetaculo_Espetaculo1_idx ON Patrocinador_Espetaculo (Espetaculo_idEspetaculo ASC) ;

CREATE INDEX fk_Patrocinador_has_Espetaculo_Patrocinador1_idx ON Patrocinador_Espetaculo (Patrocinador_nome ASC) ;


-- -----------------------------------------------------
-- Table Coreografia_has_Musica
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Coreografia_has_Musica (
Coreografia_idCoreografia INTEGER NOT NULL,
Musica_id_musica VARCHAR(45) NOT NULL,
PRIMARY KEY (Coreografia_idCoreografia, Musica_id_musica),
CONSTRAINT fk_Coreografia_has_Musica_Coreografia1
FOREIGN KEY (Coreografia_idCoreografia)
REFERENCES Coreografia (idCoreografia)

,
CONSTRAINT fk_Coreografia_has_Musica_Musica1
FOREIGN KEY (Musica_id_musica)
REFERENCES Musica (id_musica)

)
;

CREATE INDEX fk_Coreografia_has_Musica_Musica1_idx ON Coreografia_has_Musica (Musica_id_musica ASC) ;

CREATE INDEX fk_Coreografia_has_Musica_Coreografia1_idx ON Coreografia_has_Musica (Coreografia_idCoreografia ASC) ;

-- -----------------------------------------------------
-- Table Diretor_Adm_formacao_Usuario
-- -----------------------------------------------------

CREATE TABLE IF NOT EXISTS Diretor_Adm_formacao_Usuario (
Diretor_Adm_formacao_Usuario_idDiretor_adm INTEGER NOT NULL,
Diretor_Adm_formacao_Cont INTEGER NOT NULL,
Usuario_idUsuario INTEGER NOT NULL,
data_edicao DATE NOT NULL,
PRIMARY KEY (Diretor_Adm_formacao_Usuario_idDiretor_adm, Diretor_Adm_formacao_Cont, Usuario_idUsuario),

CONSTRAINT fk_Diretor_Adm_formacao_has_Usuario_Diretor_Adm_formacao1
FOREIGN KEY (Diretor_Adm_formacao_Usuario_idDiretor_adm , Diretor_Adm_formacao_Cont)
REFERENCES Diretor_Adm_formacao (Usuario_idDiretor_adm , Cont)
,
CONSTRAINT fk_Diretor_Adm_formacao_has_Usuario_Usuario1
FOREIGN KEY (Usuario_idUsuario)
REFERENCES Usuario (idUsuario)
)
;

CREATE INDEX fk_Diretor_Adm_formacao_has_Usuario_Usuario1_idx ON Diretor_Adm_formacao_Usuario (Usuario_idUsuario ASC);

CREATE INDEX fk_Diretor_Adm_formacao_has_Usuario_Diretor_Adm_formacao1_idx ON Diretor_Adm_formacao_Usuario (Diretor_Adm_formacao_Usuario_idDiretor_adm ASC, Diretor_Adm_formacao_Cont ASC);