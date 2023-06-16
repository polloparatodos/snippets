    //******************** Begin - Hand Grinder Lighting ********************
    //set ambient lighting strength
    glUniform1f(ambStrLoc, 0.4f);

    //set ambient color
    glUniform3f(ambColLoc, 0.3f, 0.3f, 0.3);

    // Diffuse light (fill light)
    glUniform3f(light1ColLoc, 0.6f, 0.6f, 0.6f);
    glUniform3f(light1PosLoc, -7.0f, 8.0f, 2.0f);
    glUniform1f(specInt1Loc, 0.4f);
    glUniform1f(highlghtSz1Loc, 0.6f);

    // Spotlight
    glUniform3f(light2ColLoc, 0.6f, 0.6f, 0.6f);
    glUniform3f(light2PosLoc, -6.0f, 8.0f, 0.0f);
    glUniform1f(specInt1Loc, 0.2f);
    glUniform1f(highlghtSz2Loc, 64.0f);

    ubHasTextureVal = true;
    glUniform1i(uHasTextureLoc, ubHasTextureVal);
    //******************** End - Hand Grinder Lighting ********************

    //******************** 1. Cylinder base - glass ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(1.0f, 2.0f, 1.0f));
    // 2. do not rotate the object
    //rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-6.0f, 0.0f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureGlassId);

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    glBindTexture(GL_TEXTURE_2D, 0);
