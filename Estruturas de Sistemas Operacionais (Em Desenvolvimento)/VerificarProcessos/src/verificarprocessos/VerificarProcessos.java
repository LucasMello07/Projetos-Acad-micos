
package verificarprocessos;

import java.io.IOException;





public class VerificarProcessos {

    
    public static void main(String[] args) {
        if (args.length > 0) {
            // Caso um nome de aplicativo seja passado como argumento
            String appName = args[0];
            try {
                Process process = new ProcessBuilder(appName).start();
                long pid = process.pid();
                System.out.println("Processo iniciado: " + appName);
                System.out.println("PID do processo: " + pid);
                // Opcional: Adicionar um hook para finalizar o processo ao sair
                Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                    process.destroy();
                }));
             } catch (IOException e) {
                System.err.println("Erro ao iniciar o processo: " + e.getMessage());
            }
        } else {
            // Caso nenhum argumento seja passado
            long pid = ProcessHandle.current().pid();
            System.out.println("Nenhum argumento fornecido.");
            System.out.println("PID do processo atual: " + pid);
        }
    }
}
    
    

