-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Mar 24, 2017 alle 21:16
-- Versione del server: 10.1.21-MariaDB
-- Versione PHP: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `glossarioswe`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `glossario`
--

CREATE TABLE `glossario` (
  `NOME` varchar(100) NOT NULL,
  `DEFINIZIONE` text,
  `ALTRO` text
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dump dei dati per la tabella `glossario`
--

INSERT INTO `glossario` (`NOME`, `DEFINIZIONE`, `ALTRO`) VALUES
('Best practice', 'Prassi(modo di fare) che per esperienza e studio abbia mostrato di garantire i migliori risultati in circostanze note e specifiche. (Il miglior modo per fare le cose).', ''),
('Ciclo di vita del SW', 'Gli stati che il prodotto assume del concepimento al ritiro.', ''),
('Efficacia', 'Determinata dal grado di conformitÃ  del prodotto rispetto alle norme vigenti e agli obbiettivi prefissati.', 'Efficacia = conformitÃ , cioÃ¨ quando soddisfiamo le attese.\r\nDa quello che ho capito: quanto soddisfiamo le richieste dell\'committente'),
('Efficenza', 'Inversamente proporzionale alla quantitÃ  di risorse impiegate nell\'esecuzione delle attivitÃ  richieste.', 'Efficenza = Ottimizazione. Minor consumo possibile.\r\nDa quello che ho capito: Quanto velocemente procediamo nel ciclo di vita.'),
('Ingegneria', 'Applicazione dei principi matematici e scientifici a scopi pratici (\"pratical ends\").', 'Pratical end: sono scopi pratici sia a livello civile e sociale, non sono solo prodotti di consumo. Questo comporta a resposabilit&agrave; etiche e sociali.'),
('Manutenzione', 'La manutenzione del ciclo di vita del software puÃ² essere di tre tipi:\r\n<ul><li><strong>Correttiva:</strong> correzione dei bug.\r\n (La peggiore perchÃ© il prodotto viene svalutato agli occhi dell\'utente</li>\r\n<li><strong>Adattativa:</strong> Per adattare il sistema alla varizione dei requisiti. (Tiene conto dei feedback dell\'utente e se ne modifica il software in base alle richieste.</li><li><strong>Evolutiva:</strong>per aggiungere funzionalitÃ  al sistema.(Sia ggiungono cose nuove al sistema)</li></ul>', 'Software buono Ã¨ quello che spende la maggior parte del proprio ciclo di vita nella MANUTENZIONE perchÃ© il prodotto continua ad essere utilizzato.'),
('Progetto', 'Insieme d\'attivitÃ  che fanno avanzare il ciclo di vita del SW.', ''),
('Steakholder (portatori d\'interesse)', 'L\'insieme di persone a vario titolo coinvolte nel ciclo di vita del SW, che hanno influenza sul prodotto o sul processo.', ''),
('Way of working', 'Modo di lavorare nella stessa maniera degli altri.', 'Metodo di ragionare:\r\n<ul><li><strong>Sistematico:</strong>adottare un metodo di lavoro che verrÃ  applicato ogni volta;</li>\r\n<li><strong>Disciplinato:</strong>norme di dominio, le cose fatte aderiscono a norme coerenti a quello che faccio;</li>\r\n<li><strong>Quantificabile:</strong>so quanto consumerÃ² per produrre quel lavoro.</li></ul>\r\nMetodo rigoroso seguire.');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `glossario`
--
ALTER TABLE `glossario`
  ADD PRIMARY KEY (`NOME`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
