package List1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class Ex6 {
    public static void main(String[] args) {
        try {
            String commandLine = String.join(" ", args);
            System.out.println(commandLine);
            List<String> commands = Stream.of(commandLine.split("\\|")).map(st -> st.trim()).toList();
            commands.forEach(System.out::println);
            List<ProcessBuilder> processBuilders = new ArrayList<>();
            for(String command : commands) {
                processBuilders.add(new ProcessBuilder(command.split(" ")));
            }
                
            List<Process> processes = ProcessBuilder.startPipeline(processBuilders);

            // Capturar a saída do último processo
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(processes.get(processes.size() - 1).getInputStream()))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    System.out.println(line);
                }
        }
        }catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}