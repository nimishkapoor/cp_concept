for (int i = 0; i < allFiles.length; i++) {
            try {
                File workingFile = allFiles[i];
                FileInputStream fileInputStream = new FileInputStream(workingFile);

                int length = (int) workingFile.length();
                byte[] buffer = new byte[length];
                try {
                    fileInputStream.read(buffer, 0, length);
                } catch (java.io.IOException e) {
                    System.err.println(COULD_NOT_FIND + workingFile + LEFT_PAR + e.getLocalizedMessage() + RIGHT_PAR);
                }
                ZipEntry zipEntry = new ZipEntry(workingFile.getName());
                jarFile.putNextEntry(zipEntry);
                jarFile.write(buffer, 0, length);
                fileInputStream.close();
            } catch (java.io.IOException e) {
                System.err.println("buildDoc: An error occurs while building the JavaHelp ( " + e.getLocalizedMessage() + RIGHT_PAR);
            }

        }
