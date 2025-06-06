       *> { dg-do run }

       IDENTIFICATION   DIVISION.
       PROGRAM-ID.      prog.
       DATA             DIVISION.
       WORKING-STORAGE  SECTION.
       01 INDVAL        PIC 9(4).
       PROCEDURE        DIVISION.
       A01 SECTION.
       A011.
           PERFORM VARYING INDVAL FROM 1 BY 1 UNTIL INDVAL > 10
            IF INDVAL > 2
               EXIT SECTION
            END-IF
           END-PERFORM.
       A012.
           DISPLAY INDVAL NO ADVANCING
           END-DISPLAY.
       A02 SECTION.
           IF INDVAL NOT = 3
              DISPLAY INDVAL NO ADVANCING
              END-DISPLAY
           END-IF.
           STOP RUN.

