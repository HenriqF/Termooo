
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class wordle {
    public static void main(String[] args){
        String palavra = "pneumoultra";
        int len = palavra.length();
        System.out.println("=".repeat(len+3));
        System.out.println("*".repeat(len) + " " + len);
        
        boolean state = true;
        while (state){
            String guess = getword(palavra);
            checkword(palavra, guess);    
        }
    }

    public static String getword(String palavra){
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String guess = "";
        try{
            guess = reader.readLine();
        }
        catch (IOException e){
            e.printStackTrace();
        }

        int len1 = palavra.length();
        int len2 = guess.length();

        if (len1 != len2){
            System.out.println("=".repeat(len1+3));
            System.out.println("tamanho indevido.");
            System.out.println("=".repeat(len1+3));
            return getword(palavra);
        }

        return guess;
    }

    public static boolean checkword(String palavra,String guess){
        String reserva = palavra;
        String out = "-".repeat(palavra.length());

        if (guess.equals(palavra)){
            System.out.println("=".repeat(palavra.length()+3));
            System.out.println("vitória!");
            System.out.println("=".repeat(palavra.length()+3));
            return true;
        }
        else{
            for(int i = 0 ; i<palavra.length() ; i++){
                if(guess.charAt(i) == (reserva.charAt(i))){
                    out = out.substring(0, i) + "o" + out.substring(i+1);
                    reserva = reserva.replaceFirst(String.valueOf(guess.charAt(i)), "0");
                }
            }
            for(int i = 0 ; i<palavra.length() ; i++){
                if(reserva.indexOf(guess.charAt(i)) != -1){
                    if (out.charAt(i) != 'o'){
                        out = out.substring(0, i) + "x" + out.substring(i+1);
                        reserva = reserva.replaceFirst(String.valueOf(guess.charAt(i)), "0");
                    }
                    
                }
            }
        }
        System.out.println(out);
        return false;
    }
}