#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>

// Paramètres du Système Updatés
// Masses
static const double mw = 0.6;
static const double mb=0.894;
static const double Ms=1.017;

// Distances
static const double rho=0.036;
static const double l=0.165;
static const double d=0.086; // distance A-C

// Electriques
static const double L=2.3e-3;
static const double R=2.2;
// r;

// Couples
static const double k=0.347;

// Moments inertie A TROUVER
static const double Iwy=1.6e-4;
static const double Ipsi=3.12e-2;

// static constantes utilitaires
static const double beta = (Ms + 2*Iwy/pow(rho, 2));
static const double gamma = Ipsi + mb*pow(d, 2); 
static const double alpha = 2/rho;
static const double etaConst = l/rho; // eta constant for phiDif

//// Trajectoire d'équilibre
// Mouvement Rectiligne Uniforme selon axe x du laboratoire.
// On néglige les perturbations sur les entrées et les mesures.

// Références
static const double ur = 0.5; //m/s
static const double psir = 0;
// for horizontal MRU only
static const double phiDifRef = 0;
static const double cLFRef = 0;

// On fait le changement right,left (r,l) -> sum,dif (s,d)
// Somme des tensions gauche et droite
// Le "s" signifie "sum", on trouvera aussi "d"
// pour "difference"
static const double Usbar = 2*k/rho*ur; // should not be >12V
static const double Udbar = 0;

static const double Urbar = Usbar/2;
static const double Ulbar = Usbar/2;

static const double Umax = 12;

static const double pbar = 0; // normally, should equals ubar*t, 
// but is not in state function, so any value fits.
static const double ubar = ur;
static const double psibar = psir;
static const double vbar = 0;
static const double Isbar = 0;
static const double Idbar = 0;
static const double ybar = 0;


//// Sous-système Lent Somme
// On a négligé Is par perturbation
// Etat=[p; u], Entrée=[Us], Sortie mesurée=[phis]

static const double Qs = k/beta/rho/R;


//// Sous-système Lent Différence
// On a négligé Id par perturbation
// Etat=[psi; v; y], Entrée=[Ud], Sortie mesurée=[phid; cLF]

static const double b1 = 1/gamma*mb*d*ubar;
static const double b2 = 1/gamma*l*k/2/rho/R;


//// Contrôleurs

//// Modèle de commande somme
// réglage PD idéal
static const double absSumEig1 = 67;
static const double w0 = 2*absSumEig1; // accélération facteur 2000
static const double xi = pow(1.0/2.0, 0.5);

// Gains
static const double h1 = pow(w0, 2)/Qs/alpha;
static const double h2 = 1/alpha*(-2*xi*w0/Qs + 2*k/rho);
static const double h3 = h1;

// PD approximé
static const double Tds = h2/h1;
static const double ns = 50; // à régler, augmente la sensibilité au bruit.


//// Modèle de commande diff

// réglage Contrôleur Idéal, PD sur phid, P sur cLF
static const double sigma = 10; // à régler, réponse très lente.
// Gains
static const double k1 = 1/b2/etaConst*pow(sigma, 2)*pow(6, 0.5);
static const double k2 = 1/b2/etaConst*(-sigma*pow(6, 0.5) - b1 + b2*k*l/rho);
static const double k3 = k1;
static const double k4 = pow(sigma, 3)/ubar/b2;
static const double k5 = k4;


// PD+P idéal

// PD+P approximé
static const double Tdd = k2/k1;
static const double nd = 50;

// Modélisation du Capteur de Ligne du Line Follower / SensorBar
static const double Nt = 127.*2;
static const double lLF = 0.15;
static const double deltaY = lLF / Nt;  

// PD capteur de ligne
static const double kcLF = 200; // Paramètres expérience vendredi 10/11 : kcLF = 55
static const double epsiloncLF = 1.0/100.0;
static const double kcLFDot = 20;

#endif