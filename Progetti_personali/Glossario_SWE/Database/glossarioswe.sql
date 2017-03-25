-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Mar 25, 2017 alle 15:33
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
('Ciclo di vita del SW', 'Gli stati che il prodotto assume del concepimento al ritiro.', 'Fattori come obblighi(contratti), regole(standard) e strategie. <ul><li>Determinano la natura degli stati d\'inizio e fine(cosa contengono);</li><li>Le pre- e post- condizioni poste sulle transazioni tra gli stati.</li></ul>\r\nQueste attivitÃ  permettono di conoscere il ciclo di vita che serve a valutare costi, tempi, obblighi e benefici associati allo svolgimento del progetto( DA FARE PRIMA DEL PROGETTO). Meglio se c\'Ã¨ un catalogo di cicli di vita(modelli astratti) in cui si puÃ² scegliere il migliore.'),
('Configurazione', 'Insieme composto di parti, quali esse sono il modo in cui esse devono stare insieme. (Ogni insieme di parti va gestito con controllo di configurazione).', 'Gestione della configurazione Ã¨ una attivitÃ  specifica. Dare alle cose il loro posto.'),
('Efficacia', 'Determinata dal grado di conformitÃ  del prodotto rispetto alle norme vigenti e agli obbiettivi prefissati.', 'Efficacia = conformitÃ , cioÃ¨ quando soddisfiamo le attese. Da massimizzare, da valutare in una checklist.\r\nDa quello che ho capito: quanto soddisfiamo le richieste dell\'committente.'),
('Efficenza', 'Inversamente proporzionale alla quantitÃ  di risorse impiegate nell\'esecuzione delle attivitÃ  richieste.', 'Efficenza = Ottimizazione. Minor consumo possibile.\r\nDa quello che ho capito: Quanto velocemente procediamo nel ciclo di vita.\r\nMisura la quantitÃ  di risorse utilizzate (Ore/Persona).'),
('Incremento', 'Procede per incrementi significa aggiungere a un impianto base.', 'Ho una chiara condizione d\'uscita. So che ad ogni passo sono avanzato(so che esco dal loop).\r\nLa somma di due parti, un punto precedente del cammino giÃ  fatto e il punto raggiunto. Dimostro al mio stakeholder che mi avvicino alla soluzione.'),
('Ingegneria', 'Applicazione dei principi matematici e scientifici a scopi pratici (\"pratical ends\").', 'Pratical end: sono scopi pratici sia a livello civile e sociale, non sono solo prodotti di consumo. Questo comporta a resposabilit&agrave; etiche e sociali.'),
('ISO/IEC 12207', 'Modello ad alto livello:\r\n<ul><li>Identifica i processi dello sviluppo SW (Descrive in termini d\'attivitÃ  e compiti elementari);</li><li>Struttura modulare che richiede specializzazione;</li> <li>Specifica responsabilitÃ  sui processi;</li><li>Identifica i prodotti dei processi</li></ul>.\r\nI processi sono relazionati in modo chiaro e distinto(ModularitÃ ).\r\nLe attivitÃ  di processo son ben definite e correlate tra loro(e cosÃ¬ anche i compiti(task) al loro interno)(Coesione).', ''),
('Iterazione', 'Procedere per iterazioni significa operare raffinamenti o rivisitazioni.', 'Strumento a rischio perchÃ© non Ã¨ quantificativo. Non so se esco dal loop.'),
('Manutenzione', 'La manutenzione del ciclo di vita del software puÃ² essere di tre tipi:\r\n<ul><li><strong>Correttiva:</strong> correzione dei bug.\r\n (La peggiore perchÃ© il prodotto viene svalutato agli occhi dell\'utente</li>\r\n<li><strong>Adattativa:</strong> Per adattare il sistema alla varizione dei requisiti. (Tiene conto dei feedback dell\'utente e se ne modifica il software in base alle richieste.</li><li><strong>Evolutiva:</strong>per aggiungere funzionalitÃ  al sistema.(Sia ggiungono cose nuove al sistema)</li></ul>', 'Software buono Ã¨ quello che spende la maggior parte del proprio ciclo di vita nella MANUTENZIONE perchÃ© il prodotto continua ad essere utilizzato. Ogni manutenzione, ha una storia che va gestita attraverso il controllo di versione (anche la parti non solo il progetto).'),
('Modelli di ciclo di vita', '<ul>\r\n<li>Descrivono come i processi si relazionano tra loro nel tempo rispetto agli stati di ciclo di vita.</li>\r\n<li>Base concettuale intorno alla quale pianificare, organizzare, eseguire e controllare lo svolgimento delle attivitÃ  necessarie.</li> </ul>', ''),
('Processi di ciclo di vita', 'Specificano le attivitÃ  che vanno svolte per causare transazioni di stato nel ciclo di vita di un prodotto SW.', 'Sono degli aggregati d\'attivitÃ  che serve a far progredire il ciclo di vita.'),
('Processo', 'Un insieme d\'attivitÃ  correlate e coese che trasformano ingressi in uscite secondo regole fissate, consumando risorse nel farlo.', 'Le attivitÃ  hanno uno specifico fine'),
('Processo definito', '<ul><li>Specializzazione di un processo standard;</li><li>Per adattarlo alle specifiche esigenze e caratteristiche aziendali.</li></ul>\r\nProcessi specializzati per azienda:\r\n<ul><li>Chiari, stabili,documentati;</li>\r\n<li>Indipendenti dal modello di ciclo di cita adottato;</li><li>Indipendenti dalle tecnologie;</li><li>Indipendenti dal dominio applicativo;</li><li>Indipendenti dalla documentazione richiesta.</li></ul>', ''),
('Processo di progetto', '<ul><li>Istanziazione di processi definiti;</li><li>Utilizzano risorse aziendali per raggiungere obirttivi prefissati e limitati nel tempo(progetto).</li></ul>\r\nProcessi specializzati per progetto:\r\n<ul><li>Ben Pianificati;</li><li>Chiare scelte si specializzazione:<ul><li>Definire lo scenario di applicazione;</li><li>Definire attivitÃ  e compiti aggiuntivi o specifici;</li><li>Organizzare le relazioni tra processi specializzati.</li></ul></li><li>Massima attenzione nell condurre il progetto<ul><li>La prima volta il progetto Ã¨ &ldquo;pilota&rdquo;.</li></ul></li><li>Valutazione critica dell\'esito <ul><li>Formalizzare e istituzionalizzare le parti che hanno ben operato.</li></ul></li></ul>', ''),
('Processo standard', '<ul><li>Riferimento di base generico;</li><li>Condiviso tra aziende diverse nello stesso dominio applicativo</li></ul>', ''),
('Progetto', 'Insieme d\'attivitÃ  che fanno avanzare il ciclo di vita del SW.', ''),
('Prototipi', '<ul><li>Servono per provare a scegliere soluzioni;</li>\r\n<li>Possono essere \'usa e getta\'(nel caso delle iterazioni) oppure fornire stati d\'incremento.(baseline)', 'Bozza, non occorre far parte del prodotto. Mi fa pensare a un iterazione, il costrutto Ã¨ immateriale il prodotto non Ã¨ avanzato.'),
('Riuso ', '<ul><li><strong>Occasionale (opprtunistico):</strong>in stile 	â€œcopia-incollaâ€ a basso costo ma scarso imapatto;</li><li><strong>Sistematico(per progetto, per prodotto, per azienda):</strong> a maggior costo ma maggior impatto.</li></ul>', 'Opportunistico non mi fa imparare e non mi fa avanzare , non quantificabile. Sistematico ho un idea che posso seguire, approccio positivo.'),
('Steakholder (portatori d\'interesse)', 'L\'insieme di persone a vario titolo coinvolte nel ciclo di vita del SW, che hanno influenza sul prodotto o sul processo.', ''),
('Tecniche', 'Sono â€œricetteâ€ per svolgere determinati compiti(Task). Vincoli o strategie di sviluppo restringono i gradi di libertÃ  disponibili nello svolgimento.', ''),
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
