import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.time.Duration;
import java.time.Instant;
import java.io.IOException;
import java.util.Scanner;
import java.time.LocalDate;

class No{
    public Personagem elemento;
    public No esq, dir;

    public No(Personagem elemento){
        this(elemento, null, null);
    }

    public No(Personagem elemento, No esq, No dir){
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

class ArvoreBinaria{
    private No raiz;

    public ArvoreBinaria(){
        raiz = null;
    }

    public void pesquisar(String x, Log log){
        System.out.print(x + " => raiz");
        boolean achou = pesquisar(x, raiz, log);
        if(achou){ 
            System.out.print(" SIM\n"); 
        } else{ 
            System.out.print(" NAO\n"); 
        }
    }

    private boolean pesquisar(String x, No i, Log log){
        boolean resp;

        if(i == null){
            log.incrementaCount();
            resp = false;
        } else if(x.equals(i.elemento.getName())){
            log.incrementaCount();
            resp = true;
        } else if(x.compareTo(i.elemento.getName()) < 0){
            log.incrementaCount();
            System.out.print(" esq");
            resp = pesquisar(x, i.esq, log);
        } else{
            System.out.print(" dir");
            resp = pesquisar(x, i.dir, log);
        }
        return resp;
    }

    public void caminharPre(){
        System.out.print("[ ");
        caminharPre(raiz);
        System.out.println("]");
    }

    private void caminharPre(No i){
        if(i != null){
            Personagem.imprimir(i.elemento);
            caminharPre(i.esq);
            caminharPre(i.dir);
        }
    }

    public void inserir(Personagem x) throws Exception{
        raiz = inserir(x, raiz);
    }

    private No inserir(Personagem x, No i) throws Exception{
        if (i == null){
            i = new No(x);
        } else if(x.getName().compareTo(i.elemento.getName()) < 0){
            i.esq = inserir(x, i.esq);
        } else if(x.getName().compareTo(i.elemento.getName()) > 0){
            i.dir = inserir(x, i.dir);
        } else{
            throw new Exception("Erro ao inserir!");
        }
        return i;
    }
}

class Log{
    public int count;
    public float time;
    public String fileName;
     
    Log(String fileName){
        this.count = 0;
        this.fileName = fileName;
    }
 
    public void incrementaCount(){
        count++;
    }
 
    public void registrarLog(){
        try {
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttempo de execução: " + this.time + " segundos  \tNúmero de comparações: " + this.count);
            writer.close();

        }catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
 
class Resposta{
    public String[] list;

    Resposta(){
        this.list = null;
    }

    Resposta(String[] list){
        this.list = list;
    }
    
    public String getList(){
        String resp = "";
        resp += '{';
        for(int i = 0; i < list.length; i++){
            resp += list[i];
            if(i != (list.length-1)) resp += ", ";
        } 
        resp += '}';
      return resp;
    }
}
 
class Personagem{
    private String id;
    private String name;
    private Resposta alternate_names;
    private Resposta alternate_actors;
    private String house;
    private String ancestry;
    private String species;
    private String patronus;
    private String actorName;
    private String eyeColour;
    private String gender;
    private String hairColour;
    private Boolean wizard;
    private Boolean hogwartsStaff;
    private Boolean hogwartsStudent;
    private Boolean alive;
    private int yearOfBirth;
    private LocalDate dateOfBirth;

    Personagem(){
        this.id = null;
        this.name = null;
        this.alternate_names = null;
        this.alternate_actors = null;
        this.house = null;
        this.ancestry = null;
        this.species = null;
        this.patronus = null;
        this.hogwartsStudent = false;
        this.actorName = null;
        this.eyeColour = null;
        this.gender = null;
        this.hairColour = null;
        this.wizard = false;
        this.hogwartsStaff = false;
        this.alive = false;
        this.yearOfBirth = -1;
        this.dateOfBirth = null;
    }

    Personagem(String id, String name, String[] alternate_names, String house, String ancestry, String species, String patronus,
    boolean hogwartsStaff, boolean hogwartsStudent, String actorName, boolean alive, String[] alternate_actors, String dateOfBirth, int yearOfBirth, String eyeColour,
    String gender, String hairColour, boolean wizard){
        this.id = id;
        this.name = name;
        this.alternate_names = new Resposta(alternate_names);
        this.house = house;
        this.ancestry = ancestry;
        this.species = species;
        this.patronus = patronus;
        this.hogwartsStaff = hogwartsStaff;
        this.hogwartsStudent = hogwartsStudent;
        this.actorName = actorName;
        this.alive = alive;
        this.alternate_names = new Resposta(alternate_actors);
        this.dateOfBirth = LocalDate.parse(dateOfBirth);
        this.yearOfBirth = yearOfBirth;
        this.eyeColour = eyeColour;
        this.gender = gender;
        this.hairColour = hairColour;
        this.wizard = wizard;
    }
 
    public void setId(String id){
        this.id = id;
    }
    public String getId(){
        return id;
    }

    public void setName(String name){
        this.name = name;
    }
    public String getName(){
        return name;
    }

    public void setAlternate_names(String[] alternate_names){
        this.alternate_names = new Resposta(alternate_names);
    }
    public String getAlternate_names(){
        return alternate_names.getList();
    }

    public void setHouse(String house){
        this.house = house;
    }
    public String getHouse(){
        return house;
    }

    public void setAncestry(String ancestry){
        this.ancestry = ancestry;
    }
    public String getAncestry(){
        return ancestry;
    }

    public void setSpecies(String species){
        this.species = species;
    }
    public String getSpecies(){
        return species;
    }

    public void setPatronus(String patronus){
        this.patronus = patronus;
    }
    public String getPatronus(){
        return patronus;
    }

    public void setHogwartsStaff(String hogwartsStaff){
        if(hogwartsStaff.equals("VERDADEIRO")){
            setHogwartsStaff(true);
        } else{
            setHogwartsStaff(false);
        }
    }
    public void setHogwartsStaff(boolean hogwartsStaff){
        this.hogwartsStaff = hogwartsStaff;
    }
    public boolean getHogwartsStaff(){
        return hogwartsStaff;
    }

    public void setHogwartsStudent(String hogwartsStudent){
        if (hogwartsStudent.equals("VERDADEIRO")){
            setHogwartsStudent(true);
        } else{
            setHogwartsStudent(false);
        }
    }
    public void setHogwartsStudent(boolean hogwartsStudent){
        this.hogwartsStudent = hogwartsStudent;
    }
    public boolean getHogwartsStudent(){
        return hogwartsStudent;
    }

    public void setActorName(String actorName){
        this.actorName = actorName;
    }
    public String getActorName(){
        return actorName;
    }

    public void setAlive(String alive){
        if(alive.equals("VERDADEIRO")){
            setAlive(true);
        } else{
            setAlive(false);
        }
    }
    public void setAlive(boolean alive){
        this.alive = alive;
    }
    public boolean getAlive(){
        return alive;
    }

    public void setAlternate_actors(String[] alternate_actors){
        this.alternate_actors = new Resposta(alternate_actors);
    }
    public String getAlternate_actors(){
        return alternate_actors.getList();
    }

    public void setDateOfBirth(String dateOfBirth){
        setDateOfBirth(LocalDate.parse(formatar(dateOfBirth)));
    }
    public void setDateOfBirth(LocalDate dateOfBirth){
        this.dateOfBirth = dateOfBirth;
    }
    public LocalDate getDateOfBirth(){
        return dateOfBirth;
    }

    public void setYearOfBirth(int yearOfBirth){
        this.yearOfBirth = yearOfBirth;
    }
    public int getYearOfBirth(){
        return yearOfBirth;
    }

    public void setEyeColour(String eyeColour){
        this.eyeColour = eyeColour;
    }
    public String getEyeOfColour(){
        return eyeColour;
    }

    public void setGender(String gender){
        this.gender = gender;
    }
    public String getGender(){
        return gender;
    }

    public void setHairColour(String hairColour){
        this.hairColour = hairColour;
    }
    public String getHairColour(){
        return hairColour;
    }

    public void setWizard(String wizard){
        if(wizard.equals("VERDADEIRO")){
            setWizard(true);
        } else{
            setWizard(false);
        }
    }
    public void setWizard(boolean wizard){
        this.wizard = wizard;
    }
    public boolean getWizard(){
        return wizard;
    }
 
    public Personagem clone() throws CloneNotSupportedException{
        Personagem novo = new Personagem();
        novo.id = this.id;
        novo.name = this.name;
        novo.alternate_names = this.alternate_names;
        novo.house = this.house;
        novo.ancestry = this.ancestry;
        novo.species = this.species;
        novo.patronus = this.patronus;
        novo.hogwartsStaff = this.hogwartsStaff;
        novo.hogwartsStudent = this.hogwartsStudent;
        novo.actorName = this.actorName;
        novo.alive = this.alive;
        novo.alternate_actors = this.alternate_actors;
        novo.dateOfBirth = this.dateOfBirth;
        novo.yearOfBirth = this.yearOfBirth;
        novo.eyeColour = this.eyeColour;
        novo.gender = this.gender;
        novo.hairColour = this.hairColour;
        novo.wizard = this.wizard;
        return novo;
    }

    public static String formatar(String date){
        String[] x = date.split("-");
        if(x[1].length() == 1){
            x[1] = '0' + x[1];
        }
        String resp = x[2] + "-" + x[1] + "-" + x[0];
        return resp;
    }
 
    public String removerParte(String x, int inicio, int fim){
        String part1 = x.substring(0, inicio);
        String part2 = x.substring(fim+1);
        return part1 + part2;
    }

    public String[] subSTringOfAlternate(String line){
        String[] resp = new String[2];
        for(int i = 2; i > 0; i--){
            int openBracket = line.indexOf("[");
            int closeBracket = line.indexOf("]");
            if(openBracket+1 != closeBracket){
                resp[resp.length - i] = line.substring(openBracket, closeBracket+1);
            } else{
                resp[resp.length - i] = "{}";
            }
            line = removerParte(line, openBracket, closeBracket);
        }
        return resp;
    }

    public String removerLista(String x, String rem){
        x = x.replace(rem, "");
        return x;
    }

    public String[] fixAlternates(String alternate){
        String[] resp = alternate.substring(1,alternate.length()-1).split("', '");
        return resp;
    }
 
    public void setDados(String line) {
        line = line.replace("\"", "");
        line = line.replace("\'", "");
        String[] alternates = subSTringOfAlternate(line);
        line = removerLista(line, alternates[0]);
        line = removerLista(line, alternates[1]);
        String[] alternateName = fixAlternates(alternates[0]);
        String[] alternateActors = fixAlternates(alternates[1]);
		String[] dados = line.split(";");
		setId(dados[0]);
		setName(dados[1]);
		setAlternate_names(alternateName);
		setHouse(dados[3]);
		setAncestry(dados[4]);
		setSpecies(dados[5]);
		setPatronus(dados[6]);
		setHogwartsStaff((dados[7]));
        setHogwartsStudent((dados[8]));
        setActorName(dados[9]);
        setAlive((dados[10]));
        setAlternate_actors(alternateActors);
        setDateOfBirth((dados[12]));
        setYearOfBirth(Integer.parseInt(dados[13]));
        setEyeColour(dados[14]);
        setGender(dados[15]);
        setHairColour(dados[16]);
        setWizard((dados[17]));
	}

    public static String booleanToString(boolean x){
        return x ? "true" : "false";
    }

    public void imprimir(String id){
		System.out.println(toString());
	}
    public static void imprimir(Personagem x){
		System.out.println(toString(x));
	}

    public String toString() {
        String resp = "["+getId()+" ## "+getName()+" ## "+getAlternate_names()+" ## "+getHouse()+" ## "+getAncestry()+" ## "+getSpecies()+" ## "+getPatronus()+" ## "+booleanToString(getHogwartsStaff())+" ## "+booleanToString(getHogwartsStudent())+" ## "+getActorName()+" ## "+booleanToString(getAlive())+" ## "+getDateOfBirth()+
        " ## "+getYearOfBirth()+" ## "+getEyeOfColour()+" ## "+getGender()+" ## "+getHairColour()+" ## "+booleanToString(getWizard())+"]";
      return resp;
    }

    public static String toString(Personagem x) {
		String resp = "[" + x.getId() + " ## " + x.getName() + " ## " + x.getAlternate_names() + " ## " + x.getHouse()+" ## " + x.getAncestry() + " ## " + x.getSpecies() + " ## " + x.getPatronus() + " ## " + booleanToString(x.getHogwartsStaff()) + " ## " +
        booleanToString(x.getHogwartsStudent()) + " ## " + x.getActorName() + " ## " + booleanToString(x.getAlive()) + " ## " + formatar(x.getDateOfBirth().toString())  + 
        " ## " + x.getYearOfBirth() + " ## " + x.getEyeOfColour() + " ## " + x.getGender() + " ## " + x.getHairColour() + " ## " + booleanToString(x.getWizard())+"]";
	  return resp;
	}
    
    public static void Pesquisar_personagem(Personagem[] p) throws Exception{
        FileReader file;
        BufferedReader bf;
        String line;
        int i = 0;

        file = new FileReader("/tmp/characters.csv");
        bf = new BufferedReader(file);

        while((line = bf.readLine()) != null){
            try{
                Personagem per = new Personagem();
                per.setDados(line);
                p[i] = per;
                i++;
            } catch(Exception e){
                e.getMessage();
            }
        }
        bf.close();
        file.close();
    }

    public static Personagem Procurar(Personagem p[], String id){
        Personagem x = new Personagem();

        for(int i = 0; i < p.length; i++){
            if ((p[i].getId()).equals(id)) {
                x = p[i];
                i = p.length;
            }
        }
        return x;
    }

    public static void inserirArvore(ArvoreBinaria arvore, Personagem personagens[], Scanner sc) throws Exception{
        String id;

        id = sc.nextLine();
        while(!id.equals("FIM")){
            Personagem novo;
            novo = Procurar(personagens, id);
            arvore.inserir(novo);
            id = sc.nextLine();
        }
    }

    public static void procuraNaArvore(ArvoreBinaria arvore, Log log,Scanner sc){
        String nome; 

        nome = sc.nextLine();
        while(!nome.equals("FIM")){ 
            arvore.pesquisar(nome, log);
            nome = sc.nextLine();
        }
    }
 
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Personagem personagens[] = new Personagem[404];
        ArvoreBinaria arvore = new ArvoreBinaria();
        Log log = new Log("/tmp/821811_arvoreBinaria.txt");

        Pesquisar_personagem(personagens); 
        inserirArvore(arvore, personagens, sc);
        Instant start = Instant.now();
        procuraNaArvore(arvore, log, sc);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        sc.close();
    }
}