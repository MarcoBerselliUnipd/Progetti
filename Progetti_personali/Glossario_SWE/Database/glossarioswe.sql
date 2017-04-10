-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Creato il: Apr 10, 2017 alle 15:34
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
('Amministratore', 'Controllo dell\'ambiente di lavoro<ul><li>Amministrazione delle risorse e delle infrastrutture</li><li>Risoluzione di problemi legati alla gestione dei processi</li><li>Gestione della documentazione di progetto(librarian)</li><li>Controllo delle versioni e configurazioni</li></ul>Funzione o ruolo?<ul><li>Funzione aziendale in organizzazioni molto strtturate, con piÃ¹ progetti simili</li><li>Ruolo di progetto in strutture con ambiti eterogenei</li></ul>', ''),
('Analista', '<ul><li>Conoscono il dominio del problema e hanno vasta esperienza professionale;</li><li>Hanno grande impatto sul successo del progetto;</li><li>Sono pochi e raramente seguono il progetto fino a conclusione.</li></ul>', ''),
('Baseline (punto d\'appoggio)', 'Punto d\'arrivo tecnico dal quale non ho bisogno di retrocedere.', ''),
('Best practice', 'Prassi(modo di fare) che per esperienza e studio abbia mostrato di garantire i migliori risultati in circostanze note e specifiche. (Il miglior modo per fare le cose).', ''),
('Caso d\'uso', 'Insieme di scenari (sequenze di azioni) che hanno in comune uno scopo finale(obiettivo) per un utente(attore).\r\nDescrivono l\'insieme di funzionalitÃ  del sistema come sono percepite dagli utenti:<ul><li>Visione esterna del sistema</li><lI>Nessun dettaglio implementativo</li></ul>', ''),
('Ciclo di vita del SW', 'Gli stati che il prodotto assume del concepimento al ritiro.', 'Fattori come obblighi(contratti), regole(standard) e strategie. <ul><li>Determinano la natura degli stati d\'inizio e fine(cosa contengono);</li><li>Le pre- e post- condizioni poste sulle transazioni tra gli stati.</li></ul>\r\nQueste attivitÃ  permettono di conoscere il ciclo di vita che serve a valutare costi, tempi, obblighi e benefici associati allo svolgimento del progetto( DA FARE PRIMA DEL PROGETTO). Meglio se c\'Ã¨ un catalogo di cicli di vita(modelli astratti) in cui si puÃ² scegliere il migliore.'),
('Configurazione', 'Insieme composto di parti, quali esse sono il modo in cui esse devono stare insieme. (Ogni insieme di parti va gestito con controllo di configurazione).', 'Gestione della configurazione Ã¨ una attivitÃ  specifica. Dare alle cose il loro posto.'),
('Continuous Integration (CI)', '&Egrave; una pratica che si applica in contesti in cui lo sviluppo del software avviene attraverso un sistema di versioning. Consiste nell\'allineamento frequente (ovvero &ldquo;molte volte al giorno&rdquo;) dagli ambienti di lavoro degli sviluppatori verso l\'ambiente condiviso(mainline). ', '<a href=\'https://it.wikipedia.org/wiki/Integrazione_continua?#Principi\'>Principi</a>'),
('Efficacia', 'Determinata dal grado di conformitÃ  del prodotto rispetto alle norme vigenti e agli obbiettivi prefissati.', 'Efficacia = conformitÃ , cioÃ¨ quando soddisfiamo le attese. Da massimizzare, da valutare in una checklist.\r\nDa quello che ho capito: quanto soddisfiamo le richieste dell\'committente.'),
('Efficenza', 'Inversamente proporzionale alla quantitÃ  di risorse impiegate nell\'esecuzione delle attivitÃ  richieste.', 'Efficenza = Ottimizazione. Minor consumo possibile.\r\nDa quello che ho capito: Quanto velocemente procediamo nel ciclo di vita.\r\nMisura la quantitÃ  di risorse utilizzate (Ore/Persona).'),
('Fase', 'La durata temporale entro uno stato di ciclo di vita o in una transazione tra essi.', ''),
('Gestione qualitÃ ', 'La funzione di piÃ¹ recente introduzione<ul><li>Funzione aziendale e non ruolo di progetto!</li></ul>Dimensioni di qualitÃ <ul><li>Dei prodotti e dei processi;</li><li>Sia verso il committente che verso la direzione aziendale.</li></ul>Dare confidenza<ul><li>Definendo e manutendo i processi aziendali(ciclo PDCA);</li><li>Verificandone la corretta applicazione.</li></ul>', ''),
('Glossario', 'Documento per disambiguare le parole.', ''),
('Governance', 'L\'intelligenza dei processi di una organizzazione. (Efficacia, efficienza, manutenzione, visione)', ''),
('Incremento', 'Procede per incrementi significa aggiungere a un impianto base.', 'Ho una chiara condizione d\'uscita. So che ad ogni passo sono avanzato(so che esco dal loop).\r\nLa somma di due parti, un punto precedente del cammino giÃ  fatto e il punto raggiunto. Dimostro al mio stakeholder che mi avvicino alla soluzione.'),
('Ingegneria', 'Applicazione dei principi matematici e scientifici a scopi pratici (\"pratical ends\").', 'Pratical end: sono scopi pratici sia a livello civile e sociale, non sono solo prodotti di consumo. Questo comporta a resposabilit&agrave; etiche e sociali.'),
('ISO/IEC 12207', 'Modello ad alto livello:\r\n<ul><li>Identifica i processi dello sviluppo SW (Descrive in termini d\'attivitÃ  e compiti elementari);</li><li>Struttura modulare che richiede specializzazione;</li> <li>Specifica responsabilitÃ  sui processi;</li><li>Identifica i prodotti dei processi</li></ul>.\r\nI processi sono relazionati in modo chiaro e distinto(ModularitÃ ).\r\nLe attivitÃ  di processo son ben definite e correlate tra loro(e cosÃ¬ anche i compiti(task) al loro interno)(Coesione).', ''),
('Iterazione', 'Procedere per iterazioni significa operare raffinamenti o rivisitazioni.', 'Strumento a rischio perchÃ© non Ã¨ quantificativo. Non so se esco dal loop.'),
('Manutenzione', 'La manutenzione del ciclo di vita del software puÃ² essere di tre tipi:\r\n<ul><li><strong>Correttiva:</strong> correzione dei bug.\r\n (La peggiore perchÃ© il prodotto viene svalutato agli occhi dell\'utente</li>\r\n<li><strong>Adattativa:</strong> Per adattare il sistema alla varizione dei requisiti. (Tiene conto dei feedback dell\'utente e se ne modifica il software in base alle richieste.</li><li><strong>Evolutiva:</strong>per aggiungere funzionalitÃ  al sistema.(Sia ggiungono cose nuove al sistema)</li></ul>', 'Software buono Ã¨ quello che spende la maggior parte del proprio ciclo di vita nella MANUTENZIONE perchÃ© il prodotto continua ad essere utilizzato. Ogni manutenzione, ha una storia che va gestita attraverso il controllo di versione (anche la parti non solo il progetto).'),
('Metodi agili', 'L\'idea base Ã¨ il concetto di â€œuser storyâ€<ul><li>Un compito significativo che l\'utente vuole svolgere con il SW richiesto</li></ul>\r\nOgni â€œuser storyâ€ Ã¨ definita da <ul><li>Un documento di descrizione</li><li>La minuta di conversazioni con il cliente( gli <i>stakeholder</i> in generale) per fissare la compresione comnune</li><li>La strategia da usare per confermare che il SW realizzato soddisfi gli obiettivi</li></ul>\r\nMigliori assunti base<ul><li>&Egrave; possibile suddividere il lavoro da fare in piccoli incrementi a valore aggiunto che possono essere sviluppati indipendentemente;\r\n</li><li>&Egrave; possibile sviluppare questi incrementi in una sequenza continua dall\'analis dei requisiti all\'integrazione</li></ul>Obiettivi strategici<ul><li>Poter constantemente dimostrare al cliente quanto Ã¨ stato fatto;</li><li>Verificare l\'avanzamento tramite progresso reale;</li><li>Dare agli sviluppatori la soddisfazione del risultato;</li><li>Assicurare che l\'intero prodotto SW Ã¨ ben integrato e verificato.</li></ul>Esempi: Scrum(caos organizzato>, Kanban(just-in-time),Scumban', ''),
('Milestone', '&Egrave; un punto di sincronizzazione.PiÃ¹ milestone marcano la transizione del progetto da una fase all\'altra.', 'Buone qualitÃ :<ol><li>Specifiche per obiettivi;</li><li>Delimitate per ampiezza e ambizioni;</li><li>Incrementali per contenuti;</li><li>Coerenti con e rilevanti per la strategia di progetto;</li><li>Misurabili per quantitÃ  di impegno necessario;</li><li>Traducibili in compiti assegnabili;</li><li>Raggiungibili;</li><li>Puntuali rispetto alle esigenze di calendario;</li><li>Dimostrabili agli stakeholder.</li></ol>'),
('Modelli di ciclo di vita', '<ul>\r\n<li>Descrivono come i processi si relazionano tra loro nel tempo rispetto agli stati di ciclo di vita.</li>\r\n<li>Base concettuale intorno alla quale pianificare, organizzare, eseguire e controllare lo svolgimento delle attivitÃ  necessarie.</li> </ul>', ''),
('Modello a coponenti', 'Nasce dall\'osservazione che molto di quello che ci serve fare Ã¨ giÃ  stato fatto e molto di quello che faremo ci potrÃ  servire ancora. Massima attenzione al riuso sistematico di componenti preesistenti proprie oppure &ldquo;of-the-shell&rdquo;', ''),
('Modello a spirale', 'Modello utilizzato dalla ricerca che ha rischi elevati. Il modello di tipo risk driven(concentrato sui rischi) cerca di alternare velocemente le fasi che sono:\r\n<ul><li>Definizione degli obiettivi(Requisiti, rischi, strategia di gestione)</li><li>Analisi dei rischi (valutazione con alternative con l\'ausilio di prototipi e simulazioni. Studio delle conseguenze)</li><li>Sviluppo e validazione(Realizzazione del prodotto)</li><li>Pianificazione (Pianificare e decidere se proseguire)</li></ul> Richiede un alta collaborazione tra cliente (definizione vincoli e obiettivi) e fornitore (sviluppo e validazione) per l\'analisi dei rischi.', ''),
('Modello evolutivo', '<ul><li>Aiuta a rispondere a bisogni non inizialmente preventivabili;</li><li>PuÃ² richiedere il rilascio e il mantenimento di piÃ¹ versioni esterne in parallelo;</li><li>Comporta il riattraversamento di piÃ¹ fasi di ciclo di vita.</li></ul><ul><li>Analisi preliminare<ul><li>Per identificare i requisiti di massima;</li><li>Per definire l\'architettura di massima</li><li>Per pianificare i passi d\'analisi e realizzazione evolutiva.</li></ul></li><li>Analisi e realizzazione di una evoluzione<ul><li>Per raffinamento ed estensione dell\'analisi;</li><li>Per progettazione,\r\n codifica, prove e integrazione.</li></ul></li><li>Rilascio di &ldquo;prototipi&rdquo;, poi accetazioone finale.</li></ul>', ''),
('Modello incrementale', '<ul><li>Prevede rilasci multipli e successivi.(Ciascuno realizza un incremento di funzionalitÃ );</li><li>I requisiti utente sono classificati e trattati in base alla loro importanza strategica<ul><li>I primi rilasci puntatno a soddisfare i requisiti piÃ¹ importanti;</li><li>I requisiti importanti sono stabili dall\'inizio.(Quelli meno importanti possono stabilizzarsi in corso di sviluppo).</li></ul></li></ul>\r\nAnalisi e progettazione architetturale <big>non</big> ripetute <ul><li>Requisiti principali sono identificati e fissati completamente;</li><li>Architettura del sistema Ã¨ identificata e fissata definitivamente;</li><li>Essenziale per pianificare i cicli d\'incremento.</li></ul>La realizzazione Ã¨ incrementale<ul><li>AttivitÃ  di progettazione di dettaglio, codifica e prove;</li><li>Prima i requisiti essenziali poi quelli desiderabili;</li><li>Integrazione, collaudo, eventuale rilascio.</li></ul>', 'Rappresenta un modello sequenziale(a cascata) con la possibilitÃ  di fare cicli d\'integrazione( ovvero che potrebbero a produrre &#34;valore&#34;) dopo i passaggi di stato di analisi e progettazione(ad alto livello). A differenza di cicli iterativi questi sono piÃ¹ sicuri(anche se non Ã¨ detto per via del budget).I cicli iterativi non assicurano che ci sia stato una analisi e una progettazione totale di tutti i moduli (anche non obbligatori) e quindi potrebbe portare a ritornare sui passi dell\'analisi e della progettazione.\r\n'),
('Modello sequenziale( a cascata)', 'Successioni di fasi rigidamente sequenziali\r\n<ul><li>Non ammette ritorno a fasi precedenti;</li><li>Eventi eccezionali fanno ripartire dall\'inizio.</li></ul>\r\nProdotti: Principalmente documenti fino ad includere il software. <ul><li>Ogni stato di vita(fase) caratterizzato da pre-condizioni d\'ingresso e post-condizioni d\'uscita;</li><li>Fasi distinte e non sovrapposte nel tempo;</li><li>Adatto allo sviluppo di sistemi complesso sul piano organizzativo.</li></ul> Ogni fase viene definita in termini di <ul><li>AttivitÃ  previste e prodotti attesi in ingresso e in uscita</li><li>Contenuti e struttura dei documenti</li><li>ResponsabilitÃ  dei ruoli coinvolti</li><li>Scadenze di consegna dei documenti</li></ul>\r\nLe fasi sono durate temporali con dipendenza casuali tra loro<ul><li>Entrare, uscire, stazionare in una fase comporta azioni specifiche;</li><li>Realizzate come attivitÃ  erogate dai processi coinvolti</li></ul>', ''),
('Piano di qualitÃ (PdQ)', 'Il documento che definisce gli elementi del SGQ(Sistema Gestione QualitÃ ) e le risorse che devono essere applicate in uno specifico caso(prodotto, processo, progetto).', 'Rientra nel documento <strong>Piano di Qualifica</strong>.'),
('Processi di ciclo di vita', 'Specificano le attivitÃ  che vanno svolte per causare transazioni di stato nel ciclo di vita di un prodotto SW.', 'Sono degli aggregati d\'attivitÃ  che serve a far progredire il ciclo di vita.'),
('Processo', 'Un insieme d\'attivitÃ  correlate e coese che trasformano ingressi in uscite secondo regole fissate, consumando risorse nel farlo.', 'Le attivitÃ  hanno uno specifico fine'),
('Processo definito', '<ul><li>Specializzazione di un processo standard;</li><li>Per adattarlo alle specifiche esigenze e caratteristiche aziendali.</li></ul>\r\nProcessi specializzati per azienda:\r\n<ul><li>Chiari, stabili,documentati;</li>\r\n<li>Indipendenti dal modello di ciclo di cita adottato;</li><li>Indipendenti dalle tecnologie;</li><li>Indipendenti dal dominio applicativo;</li><li>Indipendenti dalla documentazione richiesta.</li></ul>', ''),
('Processo di progetto', '<ul><li>Istanziazione di processi definiti;</li><li>Utilizzano risorse aziendali per raggiungere obirttivi prefissati e limitati nel tempo(progetto).</li></ul>\r\nProcessi specializzati per progetto:\r\n<ul><li>Ben Pianificati;</li><li>Chiare scelte si specializzazione:<ul><li>Definire lo scenario di applicazione;</li><li>Definire attivitÃ  e compiti aggiuntivi o specifici;</li><li>Organizzare le relazioni tra processi specializzati.</li></ul></li><li>Massima attenzione nell condurre il progetto<ul><li>La prima volta il progetto Ã¨ &ldquo;pilota&rdquo;.</li></ul></li><li>Valutazione critica dell\'esito <ul><li>Formalizzare e istituzionalizzare le parti che hanno ben operato.</li></ul></li></ul>', ''),
('Processo standard', '<ul><li>Riferimento di base generico;</li><li>Condiviso tra aziende diverse nello stesso dominio applicativo</li></ul>', ''),
('Profilo professionale', '<ul><li>Requisiti per l\'assunzione di un ruolo in un progetto;</li><li>Competenze tecnologiche e metodologiche;</li><li>Esperienza espressa in anni e partecipazione a progetti.</li></ul>', ''),
('Progettisti', '<ul><li>Hanno competenze tecnologiche e tecnologiche aggiornate e ampia esperienza professionale;</li><li>Hanno forte influenza sugli aspetti tecnici e tecnologici del progetto;</li><li>Spesso ne assumono responsabilitÃ  di scelte di gestione;</li><li>Sono pochi e talvolta seguono il prodotto fino alla manutenzione</li></ul>', ''),
('Progetto', 'Insieme d\'attivitÃ  che fanno avanzare il ciclo di vita del SW.', ''),
('Programmatori', '<ul><li>Partecipano alla realizzazione e manutenzione del prodotto;</li><li>Hanno competenze tecniche,visione e responsabilitÃ  circoscritte;</li><li>Formano la categoria storicamente piÃ¹ popolosa</li><li>Partecipano anche alla manutenzione</li></ul>', ''),
('Prototipi', '<ul><li>Servono per provare a scegliere soluzioni;</li>\r\n<li>Possono essere \'usa e getta\'(nel caso delle iterazioni) oppure fornire stati d\'incremento.(baseline)', 'Bozza, non occorre far parte del prodotto. Mi fa pensare a un iterazione, il costrutto Ã¨ immateriale il prodotto non Ã¨ avanzato.'),
('QualitÃ ', 'Insieme delle caratteristiche di un\'entitÃ  che ne determinano la capacitÃ  di soddisfare esigenze espresse e implicite.\r\nVisioni della qualitÃ :<ul><li>Intrinseca;(ConformitÃ  dei requisiti e IdoneitÃ  all\'uso)</li><li>Relativa;(Soddisfazione del cliente)</li><li>Quantitativa(Misura del livello di qualitÃ  per confronto)./li></ul> Ambiti del sistema qualitÃ :<ul><li>Pianficazione(Definizione di politica e obiettivi)</li><li>Controllo</li><li>Miglioramento Continuo</li></ul>', 'la qualitÃ  Ã© un insieme di cose influenti che possederle rendono conforme rispetto alle esigenze espresse ed implicite'),
('Quality Assurance', 'Standard sulla qualitÃ  preventivo', 'Mettere in piedi le cose in cui il controllo intervenga prima con verifiche nei punti in cui non ho certezze. Non avanzo se non sono nelle condizioni. Misurare in modo oggettivo ed non rertospettivo.'),
('Relazione di dipendenza', 'Si ha dipendenza tra due elementi di un diagramma se la modifica alla definizione del primo(fornitore) puÃ² cambiare la definizione del secondo(client).', ''),
('Requisito', '2 modi di vederlo <ul><li>Bisogno del cliente, capacitÃ  che bisogna avere per risolvere. Non c\'Ã¨ mai un requisito senza il perchÃ©;</li><li>Soluzione, ciÃ² che ho fatto in soluzione del bisogno</li></ul>', ''),
('Responsabile (Project Manager)', 'Rappresenta il progetto presso il fornitore e presso il committente<ul><li>Accentra le responsabilitÃ  di scelta e approvazione;</li><li>Partecipa al progetto per tutta la sua durata;</li><li>&Egrave; difficilmente sostituibile.</li></ul>Ha responsabilitÃ  su<ul><li>Pianficazione;</li><li>Gestione delle risorse umane;</li><li>Controllo,\r\n coordinamento e relazioni esterne.</li></ul>Deve avere conoscenze e capacitÃ  tecniche<ul><li>Per comprendere e anticipare l\'evoluzione del progetto.</li></ul>', ''),
('Riuso ', '<ul><li><strong>Occasionale (opprtunistico):</strong>in stile 	â€œcopia-incollaâ€ a basso costo ma scarso imapatto;</li><li><strong>Sistematico(per progetto, per prodotto, per azienda):</strong> a maggior costo ma maggior impatto.</li></ul>', 'Opportunistico non mi fa imparare e non mi fa avanzare , non quantificabile. Sistematico ho un idea che posso seguire, approccio positivo.'),
('Ruolo', 'Funzione assegnata al progetto\r\n<ul><li><strong>Sviluppo:</strong>responsabilitÃ  tecnica e realizzativa;</li><li><strong>Direzione:</strong>responsabilitÃ  decisionale;</li><li><strong>Amministrazione:</strong>gestione\r\n dei processi;</li><li><strong>QualitÃ :</strong>gestione della qualitÃ .</li></ul>', ''),
('Self fulfilling propercy', 'Una cosa che dico prima e so che si avvererÃ . AttivitÃ  preventiva che sto facendo bene la verifica.', ''),
('Steakholder (portatori d\'interesse)', 'L\'insieme di persone a vario titolo coinvolte nel ciclo di vita del SW, che hanno influenza sul prodotto o sul processo.', ''),
('Tecniche', 'Sono â€œricetteâ€ per svolgere determinati compiti(Task). Vincoli o strategie di sviluppo restringono i gradi di libertÃ  disponibili nello svolgimento.', ''),
('Validazione', 'Accertare che il prodotto corrisponda alle attese (Did I build the right system?). Rivolta ai prodotti finali.', ''),
('Valutazione della qualitÃ  del SW (ISO/IEC 14598)', 'Misurazione quantitativa:\'l\'uso di una metrica per assegnare un valore (numero o categoria) su una scala predefinita\'. Meglio:\'il processo attraverso cui, secondo regole definite, simboli o numeri sono assegnati ad attributi di una entitÃ \'.', ''),
('Verifica', 'Accertare che l\'esecuzione delle attivitÃ  di processo non abbia introdotto errori (Did I build the system right?).\r\nRivolta ai processi, viene svolta sui loro prodotti per accertare il rispetto di regole, convenzioni e procedure.', ''),
('Verificatori', '<ul><li>Partecipano all\'intero ciclo di vita;</li><li>Hanno competenze tecniche,\r\n esperienza di progetto, conoscenza delle norme;</li><li>Hanno capacitÃ  di giudizio e di relazione.</li></ul>', ''),
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
