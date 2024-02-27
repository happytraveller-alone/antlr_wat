import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.ParseTree;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.channels.FileChannel;
// import java.nio.file.Files;
import java.nio.file.*;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.io.PrintWriter;


/**
 * 检查WAT文件。
 * 编辑人：谢远峰
 * 日期：2023-12-21
 */
public class Check{

    /**
     * 主函数，用于启动程序。
     * @param args 命令行参数
     * @throws Exception 可能会抛出的异常
     */
    public static void main(String[] args) throws Exception {
        // 获取文件信息
        List<FileInfo> files = get_files_info();
        // 打印首个file信息
        // System.out.println("First file: " + files.get(0).getPath());
        // 打印首个file的父目录
        // System.out.println("First file's parent directory: " + files.get(0).getParentDir());
        // 打印首个file的父目录的父目录
        // System.out.println("First file's grandparent directory: " + files.get(0).getGrandparentDir());
        // 建立存储文件的文件夹
        create_folder(files);
        // 处理文件
        process_files(files);
    }
    
    /**
     * 建立存储文件的文件夹。
     *
     * @param files
     * @throws Exception
     */
    public static void create_folder(List<FileInfo> files) throws Exception{
        // 首先在当前目录建立一个文件夹，名称叫做wat_collection，如果存在，则删除重建
        File dir = new File("wat_collection");
        if (dir.exists()) {
            delete_dir(dir);
        }
        dir.mkdir();
        // 遍历文件信息列表，根据文件的所属父目录和文件名称，将父目录名称和文件名称通过"_"连接起来，
        // 作为新的文件夹名称,并在wat_collection下建立该文件夹
        for (FileInfo file : files) {
            // String common_file = file.getDestinationPath().substring(0, file.getDestinationPath().lastIndexOf("."));
            String new_dir_name = file.getParentDir() + "_" + file.getName().substring(0, file.getName().lastIndexOf("."));
            File new_dir = new File("wat_collection/" + new_dir_name);
            new_dir.mkdir();
            try {
                String sourcePath = file.getPath();
                String targetPath = "wat_collection/" + new_dir_name + "/" + file.getName();
                file.setDestinationPath(targetPath);
                // 执行文件拷贝
                copyFileUsingChannel(new File(sourcePath), new File(targetPath));
                System.out.println(file.getPath() + " copied successfully!");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        // 创建解析成功的wat文件存储文件夹
        File correct_dir = new File("wat_collection_correct");
        if (correct_dir.exists()) {
            delete_dir(correct_dir);
        }
        correct_dir.mkdir();
        // 创建解析失败的wat文件存储文件夹
        File error_dir = new File("wat_collection_error");
        if (error_dir.exists()) {
            delete_dir(error_dir);
        }
        error_dir.mkdir();
    }

     /**
     * 使用Java NIO的文件通道方式拷贝文件
     * @param source 源文件
     * @param dest 目标文件
     * @throws IOException 可能会抛出的IO异常
     */
    public static void copyFileUsingChannel(File source, File dest) throws IOException {
        FileInputStream fis = null;
        FileOutputStream fos = null;
        FileChannel sourceChannel = null;
        FileChannel destChannel = null;
        try {
            fis = new FileInputStream(source);
            fos = new FileOutputStream(dest);
            sourceChannel = fis.getChannel();
            destChannel = fos.getChannel();
            destChannel.transferFrom(sourceChannel, 0, sourceChannel.size());
        } finally {
            if (sourceChannel != null) {
                sourceChannel.close();
            }
            if (destChannel != null) {
                destChannel.close();
            }
            if (fis != null) {
                fis.close();
            }
            if (fos != null) {
                fos.close();
            }
        }
    }

    /**
     * 删除文件夹，采用非递归方法实现
     * @param files
     * @throws Exception
     */
    public static void delete_dir(File dir) throws Exception{
        // 首先判断是否是文件夹，如果不是，抛出异常
        if (!dir.isDirectory()) {
            throw new IllegalArgumentException("not a directory: " + dir);
        }
        // 创建队列存储目录
        Queue<File> queue = new LinkedList<>();
        // 将目录添加到队列
        queue.add(dir);

        // 当队列不为空时
        while (!queue.isEmpty()) {
            // 获取当前目录
            File currentDir = queue.poll();
            // 获取当前目录下的所有文件
            File[] files = currentDir.listFiles();

            // 如果文件不为空
            if (files != null) {
                // 遍历文件
                for (File file : files) {
                    // 如果是目录，添加到队列
                    if (file.isDirectory()) {
                        queue.add(file);
                    } else {
                        // 如果是文件，删除
                        file.delete();
                    }
                }
            } else {
                // 如果目录不存在或不是目录，抛出异常
                throw new IllegalArgumentException("directory not exists or is not a directory: " + currentDir);
            }
        }
        // 删除空文件夹
        dir.delete();
    }
    
    /**
     * 处理文件的函数。
     * @param files 文件信息列表
     * @throws Exception 可能会抛出的异常
     */
    public static void process_files(List<FileInfo> files) throws Exception {
        // 遍历文件信息列表
        int correct_count = 0;
        int error_count = 0;
        for (FileInfo file : files) {
            // 打印正在检查的文件名
            // System.out.println("Checking file: " + file.getPath());
            // 创建文件输入流
            InputStream is = new FileInputStream(file.getPath());
            // 创建ANTLR输入流
            CharStream input = CharStreams.fromStream(is);
            
            // 创建词法分析器
            WatLexer lexer = new WatLexer(input);
            // System.out.println("Parse tree: " + file.getPath());
            // 创建公共令牌流
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            // 创建语法分析器
            WatParser parser = new WatParser(tokens);            
            // 移除默认的词法错误监听器
            lexer.removeErrorListeners(); 
            // 移除默认的语法错误监听器
            parser.removeErrorListeners();
            // 创建输出文件公共部分
            String common_file = file.getDestinationPath().substring(0, file.getDestinationPath().lastIndexOf("."));
            // 创建词法错误输出文件
            String lexerErrorFilePath = common_file + "_lexer_errors.txt";
            PrintWriter lexerErrorOut = new PrintWriter(common_file + "_lexer_errors.txt", "UTF-8");
            // 创建语法错误输出文件
            String parserErrorFilePath = common_file + "_parser_errors.txt";
            PrintWriter parserErrorOut = new PrintWriter(common_file + "_parser_errors.txt", "UTF-8");
            // 添加词法错误监听器
            lexer.addErrorListener(createLexerErrorListener(lexerErrorOut));
            // 添加语法错误监听器
            parser.addErrorListener(createParserErrorListener(parserErrorOut)); 
            // 打印语法树
            // System.out.println("Writing to file: " + common_file + ".txt");
            // 创建PrintWriter，输出到同名文件加.txt后缀的文本文件中
            String treeFilePath = common_file + ".txt";
            try{
                ParseTree tree = parser.script();
                try (PrintWriter out = new PrintWriter(treeFilePath)) {
                    // 将语法树输出到文件
                    out.println(tree.toStringTree());
                }
            }   catch (Exception e) {
                    e.printStackTrace(parserErrorOut);
            }   finally {
                    lexerErrorOut.close();
                    parserErrorOut.close();
            }

            // 检查并删除空的错误文件
            deleteIfEmpty(lexerErrorFilePath);
            deleteIfEmpty(parserErrorFilePath);

            // 如果词法错误文件或者语法错误文件不为空，则错误计数加一，否则正确计数加一
            if(new File(lexerErrorFilePath).length() != 0 || new File(parserErrorFilePath).length() != 0) {
                error_count += 1;
                String source_parent_dir = new File(file.getDestinationPath()).getParent();
                String parent_dir = new File(file.getDestinationPath()).getParent().substring(source_parent_dir.lastIndexOf("/")+1);
                // System.out.println("source_parent_dir: " + source_parent_dir);
                // System.out.println("parent_dir: " + "wat_collection_correct/" +parent_dir);
                Path src = Paths.get(source_parent_dir);
                Path dest = Paths.get("wat_collection_error/" + parent_dir);
                Files.walk(src).forEach(source -> copy(source, dest.resolve(src.relativize(source))));
            } else {
                correct_count += 1;
                // 拷贝文件夹
                String source_parent_dir = new File(file.getDestinationPath()).getParent();
                String parent_dir = new File(file.getDestinationPath()).getParent().substring(source_parent_dir.lastIndexOf("/")+1);
                // System.out.println("source_parent_dir: " + source_parent_dir);
                // System.out.println("parent_dir: " + "wat_collection_correct/" +parent_dir);
                Path src = Paths.get(source_parent_dir);
                Path dest = Paths.get("wat_collection_correct/" + parent_dir);
                Files.walk(src).forEach(source -> copy(source, dest.resolve(src.relativize(source))));
            }
        }
        // 打印正确文件数和错误文件数
        System.out.println("\nCorrect files: " + correct_count);
        System.out.println("Error files: " + error_count);
    }

    /**
     * 拷贝文件夹的函数。
     * @param source 源文件夹
     * @param dest 目标文件夹
     */
    public static void copy(Path source, Path dest) {
        try {
            Files.copy(source, dest, StandardCopyOption.REPLACE_EXISTING);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage(), e);
        }
    }

    /*
     * 删除空的错误文件。
     */
    public static void deleteIfEmpty(String filePath) throws IOException {
        File file = new File(filePath);
        if (file.length() == 0) {
            Files.delete(file.toPath());
            System.out.println("Deleted empty file: " + filePath);
        }
    }
    
    /**
     * 词法分析错误监听器重写。
     */
    public static BaseErrorListener createLexerErrorListener(PrintWriter errorOut) {
        return new BaseErrorListener() {
            @Override
            public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol, int line, 
                                        int charPositionInLine, String msg, RecognitionException e) {
                // 打印错误信息
                errorOut.println("Failed to parse at line " + line + " due to " + msg);
                e.printStackTrace(errorOut);
            }
        };
    }
    
    /*
     * 语法分析错误监听器重写。
     */
    public static BaseErrorListener createParserErrorListener(PrintWriter errorOut) {
        return new BaseErrorListener() {
            @Override
            public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol, int line, 
                                        int charPositionInLine, String msg, RecognitionException e) {
                // 打印错误信息
                errorOut.println("Failed to parse at line " + line + " due to " + msg);
                e.printStackTrace(errorOut);
            }
        };
    }

    
    /**
     * 获取文件信息的函数。
     * @return 文件信息列表
     */
    public static List<FileInfo> get_files_info() {
        // 定义目录路径
        File dir = new File("/home/xyf/antlr_wat/wat_grammar_check_java/gc_test_file/gc_error");
        // 定义文件后缀
        String suffix = ".wast";
        // 获取文件列表
        List<FileInfo> files = listFiles(dir, suffix);
        return files;
    }

    /**
     * 列出目录下所有指定后缀的文件。
     * @param dir 目录
     * @param suffix 文件后缀
     * @return 文件信息列表
     */
    public static List<FileInfo> listFiles(File dir, String suffix){
        // 创建队列存储目录
        Queue<File> queue = new LinkedList<>();
        // 创建列表存储文件信息
        List<FileInfo> result = new ArrayList<>();
        // 将目录添加到队列
        queue.add(dir);

        // 当队列不为空时
        while (!queue.isEmpty()) {
            // 获取当前目录
            File currentDir = queue.poll();
            // 获取当前目录下的所有文件
            File[] files = currentDir.listFiles();

            // 如果文件不为空
            if (files != null) {
                // 遍历文件
                for (File file : files) {
                    // 如果是目录，添加到队列
                    if (file.isDirectory()) {
                        queue.add(file);
                    } else if (file.getName().endsWith(suffix)) {
                        // 如果文件后缀匹配，添加到结果列表
                        String parent_dir = new File(file.getParent()).getName();
                        String grandparent_dir = new File(file.getParent()).getParentFile().getName();
                        result.add(new FileInfo(file.getName(), file.getAbsolutePath(), parent_dir, grandparent_dir));
                    }
                }
            } else {
                // 如果目录不存在或不是目录，抛出异常
                throw new IllegalArgumentException("directory not exists or is not a directory: " + currentDir);
            }
        }
        return result;
    }

    /**
     * 文件信息类。
     */
    public static class FileInfo {
        private String name; // 文件名
        private String path; // 文件路径
        private String parent_dir; // 文件所属直接父目录
        private String grandparent_dir; // 文件所属直接父目录的父目录
        private String destination_path; // 文件目标路径

        /**
         * 构造函数。
         * @param name 文件名
         * @param path 文件路径
         */
        public FileInfo(String name, String path, String parent_dir, String grandparent_dir) {
            this.name = name;
            this.path = path;
            this.parent_dir = parent_dir;
            this.grandparent_dir = grandparent_dir;
        }

        /**
         * 获取文件名。
         * @return 文件名
         */
        public String getName() {
            return name;
        }

        /**
         * 获取文件路径。
         * @return 文件路径
         */
        public String getPath() {
            return path;
        }

        /**
         * 获取文件所属直接父目录。
         * @return 文件所属直接父目录
         */
        public String getParentDir() {
            return parent_dir;
        }

        /**
         * 获取文件所属直接父目录的父目录。
         */
        public String getGrandparentDir() {
            return grandparent_dir;
        }

        /**
         * 获取文件目标路径。
         */
        public String getDestinationPath() {
            return destination_path;
        }

        /**
         * 设置文件目标路径。
         */
        public void setDestinationPath(String destination_path) {
            this.destination_path = destination_path;
        }
    }
}
