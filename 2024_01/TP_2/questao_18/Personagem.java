import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.time.Duration;
import java.time.Instant;
import java.io.IOException;
import java.util.Scanner;
import java.time.LocalDate;
 
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

class Log{
    public int count;
    public int movimentacoes;
    public float time;
    public String fileName;
     
    Log(String fileName){
        this.count = 0;
 
        this.fileName = fileName;
    }
 
    public void incrementaCount(){
        count++;
    }
    public void incrementaMovimentacoes(){
        movimentacoes++;
     }
 
    public void registrarLog(){
        try {
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttempo de execução: " + this.time + " segundos  \tNúmero de comparações: " + this.count + "\tNúmero de movimentações: " + this.movimentacoes);
            writer.close();

        }catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
        }
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

    public static Scanner sc = new Scanner(System.in);

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

    public static void Exibir(Personagem personagens[]){
        for(int i = 0; i < 10; i++){
            imprimir(personagens[i]);
        }
    }

    public static void swap(Personagem personagens[], int i, int j, Log log){
        Personagem tmp = personagens[i];
        personagens[i] = personagens[j];
        personagens[j] = tmp;

        log.incrementaMovimentacoes(); 
        log.incrementaMovimentacoes(); 
        log.incrementaMovimentacoes();
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

    public static boolean comparar(Personagem a, Personagem b, Log log){
        boolean resposta = false;

        if(a.getHouse().compareTo(b.getHouse()) < 0){
            resposta = true;
            log.incrementaCount();
        } else if(a.getHouse().compareTo(b.getHouse()) > 0){
            resposta = false;
            log.incrementaCount();
            log.incrementaCount();
        } else{  
            log.incrementaCount();  
            log.incrementaCount();                                          
            if(a.getName().compareTo(b.getName()) < 0){
                resposta = true;
            } else{
                resposta = false;
            }
                log.incrementaCount();
            }
        
        return resposta;
    }
    
    public static int Pesquisar_personagem(Personagem[] p) throws Exception{
        FileReader file;
        BufferedReader bf;
        String line, id;
        int i = 0;

        file = new FileReader("/tmp/characters.csv");
        bf = new BufferedReader(file);

        id = sc.nextLine();
        while(!id.equals("FIM")){
            file = new FileReader("/tmp/characters.csv");
            bf = new BufferedReader(file);

            while((line = bf.readLine()) != null){
                try{
                    String[] dados = line.split(";");
                    if(id.equals(dados[0])){
                        Personagem personagem = new Personagem();
                        personagem.setDados(line);
                        p[i] = personagem;
                        i++;
                        break;
                    }
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
            id = sc.nextLine();
        }
        bf.close();
        file.close();
        return i;
    }

    public static void quicksort(Personagem sub[], Log log, int esq, int dir) {
        int i = esq, j = dir;
        Personagem pivo = sub[(dir+esq)/2];
        while (i <= j) {
            while (comparar(sub[i], pivo, log)) i++;
            while (comparar(pivo, sub[j], log)) j--;
            if (i <= j) {
                swap(sub, i, j, log);
                i++;
                j--;
            }
        }
        if(esq < j){  
            quicksort(sub, log, esq, j);
        }
        if(i < dir && i < 10){  
            quicksort(sub, log,  i, dir);
        }
    }
 
    public static void main(String[] args) throws Exception{
        Personagem personagens[] = new Personagem[404];
        Log log;
        int tamanho;
        Instant start, end;
        
        log = new Log("/tmp/821811_quicksort.txt");
        tamanho = Pesquisar_personagem(personagens);
        start = Instant.now();
        quicksort(personagens, log, 0, tamanho - 1);
        end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000;
        log.registrarLog();
        Exibir(personagens);
        
    }
}