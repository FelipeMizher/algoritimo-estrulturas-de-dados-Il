import java.time.LocalDate;
import java.util.Scanner;
import java.io.FileReader;
import java.io.BufferedReader;

class Celula{
    Personagem elemento;
    Celula prox;
    Celula(){
        this(null);
    }
    Celula(Personagem p){
        this.prox = null;
        this.elemento = p;
    }
}

class Pilha{
    public Scanner sc;
    public Celula topo;

    Pilha(int tamanho){
        topo = null;
        this.sc = new Scanner(System.in);
    }

    void inserirInicio(Personagem personagem) throws Exception{
        Celula tmp = new Celula(personagem);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }

    Personagem removerInicio() throws Exception{
        if(topo == null){
            throw new Exception("ERRO");
        }

        Personagem resposta = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return resposta;
    }

    public void metodos(Personagem p[], int x) {
        String m = "";
        Personagem novo;

        for(int i = 0; i < x + 1; i++){
            m = sc.nextLine();
            String[] str = m.split(" ");
            try{
                if(str[0].equals("R")){
                    Personagem removido = removerInicio();
                    System.out.println("(R) " +removido.getName());
                } else{
                    novo = Procurar(p, str[1]);
                    inserirInicio(novo);
                }
            } catch(Exception e){
                e.getMessage();
            }
        }
        System.out.println("[ Top ]");
        mostrar();
        System.out.println("[ Bottom ]");
    }

    Personagem Procurar(Personagem p[], String id) {
        Personagem x = new Personagem();

        for(int i = 0; i < p.length; i++){
            if(p[i].getId().equals(id)){
                try{
                    x = p[i].clone();
                    i = p.length;
                }catch (CloneNotSupportedException e){
                    e.getMessage();
                }
            }
        }
       return x;
    }

    void mostrar(){
        int j = 0;

        Celula i = topo;
		while(i != null) { 
            Personagem.imprimir(i.elemento, j++);
            i = i.prox;
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
            if(i != (list.length - 1)){
                 resp += ", ";
            }
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
    public int tamanho = 0;
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
        String part2 = x.substring(fim + 1);
        return part1 + part2;
    }

    public String[] subSTringOfAlternate(String line){
        String[] resp = new String[2];

        for(int i = 2; i > 0; i--){
            int openBracket = line.indexOf("[");
            int closeBracket = line.indexOf("]");
            if(openBracket + 1 != closeBracket){
                resp[resp.length - i] = line.substring(openBracket, closeBracket + 1);
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
        String[] resp = alternate.substring(1,alternate.length() - 1).split("', '");
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

    public void imprimir(String id){
		System.out.println(toString());
	}
    public static void imprimir(Personagem x, int id){
		System.out.println(toString(x, id));
	}

    public String toString() {
        String resp = "[" + getId() + " ## " + getName() + " ## " + getAlternate_names() + " ## " + getHouse() + " ## " + getAncestry() 
                + " ## " + getSpecies() + " ## " + getPatronus() + " ## " + getHogwartsStaff() + " ## " + getHogwartsStudent() + " ## "
                + getActorName() + " ## " + getAlive() + " ## " + getDateOfBirth() + " ## " + getYearOfBirth() + " ## " + getEyeOfColour() 
                + " ## " + getGender() + " ## " + getHairColour() + " ## " + getWizard() + "]";
        return resp;
    }

    public static String toString(Personagem x, int id) {
        String resp = "[" + id + " ## " + x.getId() + " ## " + x.getName() + " ## " + x.getAlternate_names() + " ## " + x.getHouse()
                + " ## " + x.getAncestry() + " ## " + x.getSpecies() + " ## " + x.getPatronus() + " ## " + x.getHogwartsStaff() + " ## " 
                + x.getHogwartsStudent() + " ## "+ x.getActorName() + " ## " + x.getAlive() + " ## " + formatar(x.getDateOfBirth().toString()) 
                + " ## " + x.getYearOfBirth() + " ## " + x.getEyeOfColour() + " ## " + x.getGender() + " ## "+ x.getHairColour() + " ## " + x.getWizard() + "]";
        return resp;
    }

    public static void Exibir(Personagem[] p) throws Exception{
        FileReader file;
        BufferedReader bf;
        String line;
        int i = 0;

        file = new FileReader("/tmp/characters.csv");
        bf = new BufferedReader(file);

		while((line = bf.readLine()) != null){
            try{
                Personagem personagem = new Personagem();
			    personagem.setDados(line);
                p[i] = personagem;
                i++;
            } catch(Exception e){
                e.getMessage();
            }
            
		}
		bf.close();
        file.close();
	}

    public static void main(String[] args) throws Exception{
        Personagem personagens[] = new Personagem[404];
        Pilha list = new Pilha(404);
        String id;

        Exibir(personagens); 
        id = list.sc.nextLine();
        while(!id.equals("FIM")){
            Personagem novo = list.Procurar(personagens, id);
            list.inserirInicio(novo);
            id = list.sc.nextLine();
        }
        int n = list.sc.nextInt();
        list.metodos(personagens, n);
        list.sc.close();
    }
}