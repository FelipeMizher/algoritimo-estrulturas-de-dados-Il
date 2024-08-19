import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;

public class html{
    public static String getHTML(String urlString){
        StringBuilder resp = new StringBuilder();
        try {
            URL url = new URL(urlString); 
            try(BufferedReader bf = new BufferedReader(new InputStreamReader(url.openStream()))){
                String line;
                while((line = bf.readLine()) != null){
                    resp.append(line);
                }
            }
        } catch(MalformedURLException mue){
            mue.printStackTrace();
        } catch(IOException e){
            e.printStackTrace();
        }
    
        return resp.toString();
    }

    private static int countVariaveis(String str, String sub) {
        int lastIndex = 0;
        int count = 0;
        while ((lastIndex = str.indexOf(sub, lastIndex)) != -1) {
            count++;
            lastIndex += sub.length();
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name, urlString;
        while (!(name = sc.nextLine()).equals("FIM")) {
            urlString = sc.nextLine();
            String htmlContent = getHTML(urlString);

            int a = 0, e = 0, i = 0, o = 0, u = 0;
            int á = 0, é = 0, í = 0, ó = 0, ú = 0;
            int à = 0, è = 0, ì = 0, ò = 0, ù = 0;
            int ã = 0, õ = 0, consoante = 0, br = 0, table = 0;
            int â = 0, ê = 0, î = 0, ô = 0, û = 0;

            for (char ch : htmlContent.toLowerCase().toCharArray()) {
                switch (ch) {
                    case 'a':
                        a++;
                        break;
                    case 'á':
                        á++;
                        break;
                    case 'e':
                        e++;
                        break;
                    case 'é':
                        é++;
                        break;
                    case 'i':
                        i++;
                        break;
                    case 'í':
                        í++;
                        break;
                    case 'o':
                        o++;
                        break;
                    case 'ó':
                        ó++;
                        break;
                    case 'u':
                        u++;
                        break;
                    case 'ú':
                        ú++;
                        break;
                    case 'à':
                        à++;
                        break;
                    case 'è':
                        è++;
                        break;
                    case 'ì':
                        ì++;
                        break;
                    case 'ò':
                        ò++;
                        break;
                    case 'ù':
                        ù++;
                        break;
                    case 'ã':
                        ã++;
                        break;
                    case 'õ':
                        õ++;
                        break;
                    case 'â':
                        â++;
                        break;
                    case 'ê':
                        ê++;
                        break;
                    case 'î':
                        î++;
                        break;
                    case 'ô':
                        ô++;
                        break;
                    case 'û':
                        û++;
                        break;
                    default:
                        if (Character.isLetter(ch)) {
                            consoante++;
                        }
                        break;
                }
            }

            br = countVariaveis(htmlContent, "<br>");
            table = countVariaveis(htmlContent, "<table>");

            System.out.println("a(" + a + ") e(" + e + ") i(" + i + ") o(" + o + ") u(" + u + ") á(" + á + ") é(" + é + ") í(" + í + ") ó(" + ó + ") ú(" + ú + ") à(" + à + ") è(" + è + ") ì(" + ì + ") ò(" + ò + ") ù(" + ù + ") ã(" + ã + ") õ(" + õ + ") â(" + â + ") ê(" + ê + ") î(" + î + ") ô(" + ô + ") û(" + û + ") consoante(" + consoante + ") <br>(" + br + ") <table>(" + table + ") " + name);
        }

        sc.close();
    }
}
